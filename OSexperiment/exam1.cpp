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
using namespace std;
class PCB;
class RCB;
vector<PCB*> process_pool;
vector<RCB*> resourse_pool;
vector<PCB*> ready_queue[6];
PCB* cur_proc;
void create(string procrss_id, int priority);
void destory(string process_id);
vector<PCB*>::iterator find_queue1(vector<PCB*> &tar_queue, string proc_id);
vector<RCB*>::iterator find_queue2(vector<RCB*> &tar_queue, string resourse_id);
PCB* get_PCB(string process_id, vector<PCB*>::iterator& p);
RCB* get_RCB(string resourse_id);
void scheduler();
class RCB
{
public:
    string ID;
    string status;
    vector<PCB*> wait_queue;
    RCB(string id) :ID(id) 
    {
        this->status = "free";
        resourse_pool.push_back(this);
    }
};


class PCB
{
public:
    string ID;
    vector<RCB*> resourse_list;
    string status;
    RCB* block_res;
    int priority;
    PCB(string id, int p) :ID(id), priority(p)
    {
        this->block_res = NULL;
    }
    void request(string RID);
    void release(string RID);
};


void PCB::request(string RID)
{
    RCB* resourse_ptr;
    resourse_ptr = get_RCB(RID);
    if (resourse_ptr->status == "free")
    {
        resourse_ptr->status = "allocated";
        this->resourse_list.push_back(resourse_ptr);
    }
    else
    {
        this->status = "blocked";
        this->block_res = resourse_ptr;
        cout << "process " << this->ID << " blocked;";
        resourse_ptr->wait_queue.push_back(this);  
    }
    scheduler();
}
void PCB::release(string RID)
{
    RCB* resourse_ptr;
    resourse_ptr = get_RCB(RID);
    vector<RCB*>::iterator p = find_queue2(this->resourse_list, resourse_ptr->ID);
    this->resourse_list.erase(p);
    if (resourse_ptr->wait_queue.empty())
    {
        resourse_ptr->status = "free";
    }
    else
    {
        PCB* proc_ptr = resourse_ptr->wait_queue[0];
        resourse_ptr->wait_queue.erase(resourse_ptr->wait_queue.begin());
        proc_ptr->block_res = NULL;
        proc_ptr->status = "ready";
        ready_queue[proc_ptr->priority].push_back(proc_ptr);
    }
    scheduler();
}

void create(string procrss_id, int priority)
{
    PCB* new_proc;
    new_proc = new PCB(procrss_id, priority);
    new_proc->status = "ready";
    process_pool.push_back(new_proc);
    if (procrss_id == "init")
    {
        new_proc->status = "run";
        cur_proc = new_proc;
        return;
    }
    ready_queue[priority].push_back(new_proc);
    scheduler();
}

void destory(string process_id)
{
    PCB* proc_ptr;
    vector<PCB*>::iterator pool_ptr;
    proc_ptr = get_PCB(process_id, pool_ptr);
    vector<PCB*>::iterator queue_ptr;
    if (proc_ptr == NULL)
    {
        exit(-1);
    }
    if (proc_ptr->status == "ready")
    {
        queue_ptr = find_queue1(ready_queue[proc_ptr->priority], proc_ptr->ID);
        ready_queue[proc_ptr->priority].erase(queue_ptr);
    }
    else if (proc_ptr->status == "blocked")
    {
        queue_ptr = find_queue1(proc_ptr->block_res->wait_queue, proc_ptr->ID);
        proc_ptr->block_res->wait_queue.erase(queue_ptr);

    }
    else if (proc_ptr->status == "run")
    {
        cur_proc = NULL;
    }
    else
    {
        exit(-2);
    }
    delete proc_ptr;
    process_pool.erase(pool_ptr);
    scheduler();
}

vector<PCB*>::iterator find_queue1(vector<PCB*> &tar_queue, string proc_id)
{
    vector<PCB*>::iterator i;
    for (i = tar_queue.begin(); i != tar_queue.end(); i++)
    {
        if ((*i)->ID == proc_id)
        {
            break;
        }
    }
    return i;
}

vector<RCB*>::iterator find_queue2(vector<RCB*> &tar_queue, string resourse_id)
{
    vector<RCB*>::iterator i;
    for (i = tar_queue.begin(); i != tar_queue.end(); i++)
    {
        if ((*i)->ID == resourse_id)
        {
            break;
        }
    }
    return i;
}
PCB* get_PCB(string process_id, vector<PCB*>::iterator& p)
{
    vector<PCB*>::iterator i;
    PCB* temp = NULL;
    for (i = process_pool.begin(); i != process_pool.end(); i++)
    {
        if ((*i)->ID == process_id)
        {
            temp = *i;
            break;
        }
    }
    p = i;
    return temp;
}
RCB* get_RCB(string resourse_id)
{
    vector<RCB*>::iterator i;
    RCB* temp = NULL;
    for (i = resourse_pool.begin(); i != resourse_pool.end(); i++)
    {
        if ((*i)->ID == resourse_id)
        {
            temp = *i;
            break;
        }
    }
    return temp;
}

PCB* get_proc()
{
    for (int i = 5; i >= 0; i--)
    {
        if (!ready_queue[i].empty())
        {
            return ready_queue[i][0];
        }
    }
}
void preempt(PCB* new_proc)
{
    new_proc->status = "run";
    if (cur_proc == NULL || cur_proc->status == "blocked")
    {
        cur_proc = new_proc;
    }
    else if (cur_proc->status == "run")
    {
        cur_proc->status = "ready";
        ready_queue[cur_proc->priority].push_back(cur_proc);
        cur_proc = new_proc;
    }
    else
    {
        exit(-3);
    }
}
void pop_queue(PCB* proc)
{
    vector<PCB*>::iterator i;
    for (i = ready_queue[proc->priority].begin(); i != ready_queue[proc->priority].end(); i++)
    {
        if ((*i)->ID == proc->ID)
        {
            ready_queue[proc->priority].erase(i);
            break;
        }
    }
}

void scheduler()
{
    PCB* proc_ptr = get_proc();
    if (cur_proc == NULL||(cur_proc->priority) < (proc_ptr->priority) || cur_proc->status != "run" )
    {
        pop_queue(proc_ptr);
        preempt(proc_ptr);
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
void sheell_put()
{
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
        if (data[0] == "cr")
        {
            stringstream ss;
            ss << data[2];
            int n;
            ss >> n;
            create(data[1], n);
        }
        else if (data[0] == "rq")
        {
            cur_proc->request(data[1]);
        }
        else if (data[0] == "rl")
        {
            cur_proc->release(data[1]);
        }
        else if (data[0] == "de")
        {
            destory(data[1]);
        }
        else
        {
            exit(-4);
        }
        cout << "process " << cur_proc->ID << " is running" << endl;
    }
}
int main()
{
    create("init", 0);
    RCB* r1 = new RCB("Q");
    RCB* r2 = new RCB("W");
    RCB* r3 = new RCB("E");
    RCB* r4 = new RCB("T");
    sheell_put();
}