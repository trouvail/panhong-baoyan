#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,k;
int h;
vector<int> max_nums;
map<int,vector<int> > mp;
int main()
{
    //input
    cin>>n>>m>>k;
    for(int i = 1;i<=n;++i){
        cin>>h;
        mp[h].push_back(i);
    }

    /*operation:
    (1)ͳһ����һ��������������С������������ÿ�����hΪ������㣬�����[h,h+k)���cell�У��Ƿ����ҹ�m��
        ��:���¼���������������߱�ţ�����һ����¼ÿ��С����max_num��vector��
        ��:��������ǰ��������һ���ڵ�ѭ����
    (2)ɨ��һ������max_num�������У�ֵ��С�ģ�������������Ҫ���Ե�������
    ��3�����Ӷȣ�Ӧ����O(m*n);
    */
    map<int,vector<int> >::iterator it1 = mp.begin();//��������ָ�룬���������ϵ�һ��С����
    map<int,vector<int> >::iterator it2 = it1;

    for(;it1!=mp.end();++it1){
        int counts = 0;
        int max_num = -1;
        bool enough_flag = false;
        int min_high = it1->first;//��¼���Сcell�е���С��ߣ�����׼��ߣ������������֮�Ӧ������k
        for(it2 = it1;it2!=mp.end();++it2){
            if(it2->first - min_high <= k && counts <= m){
                counts += it2->second.size();
                if(it2->second[it2->second.size()-1] > max_num ){
                    max_num = it2->second[it2->second.size()-1];
                }
            }else if(counts == m) {
                enough_flag = true;
                break;
            }else  break;
        }
        if(max_num !=-1 && enough_flag ==true ) max_nums.push_back(max_num);
     }

     //�����������ҵ�����С�����ϵ���С�ı��
     int i= max_nums.size();
     vector<int>::iterator it3 = max_nums.begin();
     sort(it3,it3+i);

     if(!max_nums.empty()){
        cout<<max_nums.front()<<endl;
     }else
        cout<<"impossible"<<endl;

    return 0;
}
