#include <iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
   int n;
   int m;
   cin>>n>>m;
   vector<queue<int>>balls(m);
   map<int,set<int>>freq;
   bool flag =false;
   queue<int>pending;
   for(int i=0;i<m;i++)
   {
       int sizee;
       cin >> sizee;
       for (int j = 0; j < sizee; j++)
       {
           int num;
           cin >> num;
           balls[i].push(num);
           if (j == 0) {
               freq[num].insert(i);
               if (freq[num].size() >= 2)
               {
                   pending.push(num);
               }
           }

       }
   }
   bool flag2 = false;


       while(!pending.empty())
       {

//           for(auto i:freq)
//           {
//               cout<<i.first<<' ';
//               for(auto k:i.second)
//               {
//                   cout<<k<<',';
//               }
//               cout<<endl;
//           }

           flag2 = false;

           int num = pending.front();
           pending.pop();
           auto it = freq[num].begin();
           int q1 = *it;  // First queue index
           int q2 = *(++it);  // Second queue index

           // Pop the front elements
           balls[q1].pop();
           balls[q2].pop();

           // Clear freq[num] since its conflict is resolved
           freq[num].clear();

           // Update freq for new front elements
           if (!balls[q1].empty())
           {
               int new_num = balls[q1].front();
               freq[new_num].insert(q1);
               if (freq[new_num].size() == 2) {
                   pending.push(new_num);
               }
           }
           if (!balls[q2].empty()) {
               int new_num = balls[q2].front();
               freq[new_num].insert(q2);
               if (freq[new_num].size() == 2) {
                   pending.push(new_num);
               }
           }


//           cout<<"======================================="<<endl;

       }


       int count=0;
       for(auto i:balls)
       {
           if(i.empty())
           {
               count++;
           }
       }

       if(count==m)
       {
           cout<<"Yes"<<endl;
       }
       else
       {
           cout<<"No"<<endl;
       }

















}
