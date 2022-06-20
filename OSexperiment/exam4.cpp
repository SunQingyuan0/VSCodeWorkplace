#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iterator>
#include<iostream>
#include<sstream>
#include<cstdio>
#include <fstream>
#define PROCESS_NUM 5
#define RESOURSE_NUM 3
using namespace std;

int available[PROCESS_NUM];
int sign[PROCESS_NUM];
int Max[PROCESS_NUM][RESOURSE_NUM];
int allocated[PROCESS_NUM][RESOURSE_NUM];
int need[PROCESS_NUM][RESOURSE_NUM];
void read_file()
{

    ifstream fd("data.txt", ios::in);
    if (!fd)
    {
        exit(-1);
    }
    else
    {
        int data;
        for (int j = 0; j < PROCESS_NUM; j++)
        {
            for (int i = 0; i < RESOURSE_NUM; i++)
            {
                fd >> data;
                Max[j][i] = data;
            }
            for (int i = 0; i < RESOURSE_NUM; i++)
            {
                fd >> data;
                allocated[j][i] = data;
            }
            for (int i = 0; i < RESOURSE_NUM; i++)
            {
                fd >> data;
                need[j][i] = data;
            }
            if (j == 0)
            {
                for (int i = 0; i < RESOURSE_NUM; i++)
                {
                    fd >> data;
                    available[i] = data;
                }
            }
        }
        fd.close();
    }
}
int is_safe(int available[], int need[][RESOURSE_NUM], int allocated[][RESOURSE_NUM])
{
    int proc_cnt = 0;
    int resourse_cnt = 0;
    int safety_list_cnt = 0;
    int finish_cnt = 0;
    int work[RESOURSE_NUM];
    int finish[PROCESS_NUM];
    memset(finish, 0, PROCESS_NUM * sizeof(int));
    for (int i = 0; i < RESOURSE_NUM; i++)
        work[i] = available[i];
    while (proc_cnt < PROCESS_NUM)
    {
        if (finish[proc_cnt] == 0)
        {
            while (resourse_cnt < RESOURSE_NUM && need[proc_cnt][resourse_cnt] <= work[resourse_cnt])
                resourse_cnt++;
            if (resourse_cnt == RESOURSE_NUM)
            {
                for (int i = 0; i < RESOURSE_NUM; i++)
                {
                    work[i] = work[i] + allocated[proc_cnt][i];
                }
                finish[proc_cnt] = 1;
                sign[safety_list_cnt] = proc_cnt;
                proc_cnt = -1;
                safety_list_cnt++;
            }
        }
        resourse_cnt = 0;
        proc_cnt++;
    }
    for (int i = 0; i < PROCESS_NUM; i++)
    {
        if (finish[i] == 1)
            finish_cnt++;
    }
    return finish_cnt;
}
int banker(int proc_num, int request[][RESOURSE_NUM])
{
    for (int i = 0; i < RESOURSE_NUM; i++)
    {
        if (request[proc_num][i] > need[proc_num][i])
        {
            cout << "err 1" << endl;
            return 0;
        }
        else if (request[proc_num][i] > available[i])
        {
            cout << "err 2" << endl;
            return 0;
        }
    }
    for (int i = 0; i < RESOURSE_NUM; i++)
    {
        available[i] = available[i] - request[proc_num][i];
        allocated[proc_num][i] = allocated[proc_num][i] + request[proc_num][i];
        need[proc_num][i] = need[proc_num][i] - request[proc_num][i];
    }
    int n = is_safe(available, need, allocated);
    cout << endl;
    if (n == PROCESS_NUM)
    {
        cout << "safe for " << proc_num << endl;
    }
    else
    {
        for (int i = 0; i < RESOURSE_NUM; i++)
        {
            available[i] = available[i] + request[proc_num][i];
            allocated[proc_num][i] = allocated[proc_num][i] - request[proc_num][i];
            need[proc_num][i] = need[proc_num][i] + request[proc_num][i];
        }
        cout << "not safe for " << proc_num << endl;
    }
    return n;
}

void output_res(int result)
{
    if (result == PROCESS_NUM)
    {
        cout << endl
            << "safety list:";
        for (int i = 0; i < PROCESS_NUM; i++)
        {
            cout << " " << sign[i] << " ";
        }
    }
    else
    {
        cout << "can't discover safety list" << endl;
    }
}
vector<string> split(string str)
{
    string pattern = " ";
    string::size_type pos;
    vector<std::string> result;
    str += pattern;
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        pos = str.find(pattern, i);
        if (pos < size)
        {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}
int get_num(string tar)
{
    return atoi(tar.c_str());
}
void release(int proc, int rescourse, int num)
{
    available[rescourse] += num;
    allocated[proc][rescourse] -= num;
    need[proc][rescourse] += num;
}
void sheell_put()
{
    read_file();
    while (true)
    {
        cout << ">";
        string command;
        getline(cin, command);
        if (command == "q")
        {
            break;
        }
        vector<string> data = split(command);
        if (data[0] == "req")
        {
            int proc_num = get_num(data[1]);
            int request[PROCESS_NUM][RESOURSE_NUM];
            memset(request, 0, sizeof(request));
            for (int i = 0; i < RESOURSE_NUM; i++)
            {
                request[proc_num][i] = get_num(data[i + 2]);
            }
            int res = banker(proc_num, request);
            output_res(res);
        }
        else if (data[0] == "rq")
        {
            int proc_num = get_num(data[1]);
            int request[PROCESS_NUM][RESOURSE_NUM];
            memset(request, 0, sizeof(request));
            int resourse_num = get_num(data[2]);
            int num = get_num(data[3]);
            request[proc_num][resourse_num] = num;
            int res = banker(proc_num, request);
            output_res(res);
        }
        else if (data[0] == "rl")
        {
            int proc_num = get_num(data[1]);
            int resourse_num = get_num(data[2]);
            int num = get_num(data[3]);
            release(proc_num, resourse_num, num);
        }
        else
        {
            exit(-4);
        }
        cout << endl;
    }
}
int main()
{
    sheell_put();
}

