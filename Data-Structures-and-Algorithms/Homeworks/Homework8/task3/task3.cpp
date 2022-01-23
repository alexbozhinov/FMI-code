#include <bits/stdc++.h>
using namespace std;

struct Student{
    long long submitTime;
    long long linesCode;

    Student(long long submitTime = 0, long long linesCode = 0){
       this->submitTime = submitTime;
       this->linesCode = linesCode;
    }

    friend bool operator< (const Student& st1, const Student& st2){ //vector sort
       if(st1.submitTime < st2.submitTime) return true;
       else return false;
    }
};

class myComparison{ //greater linesCode priorirty quque comp function
   public:

       bool operator()(const Student& st1, const Student& st2){
          if(st1.linesCode > st2.linesCode) return true;
          else return false;
       }
};

vector<Student> students;
priority_queue<Student, vector<Student>, myComparison> studentsPQ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        long long submitTime;
        long long linesCode;
        scanf("%lld%lld", &submitTime, &linesCode);
        //cin>>submitTime>>linesCode;
        Student newStudent(submitTime, linesCode);
        students.push_back(newStudent);
    }

    int indx = 0;
    long long totalTime = 0;
    long long currTime = 0;
/*
    for(int i=0;i<students.size();i++){
        cout<<students[i].submitTime<<"  "<<students[i].linesCode<<endl;
    }
*/
    sort(students.begin(), students.end());
/*
    for(int i=0;i<students.size();i++){
        cout<<students[i].submitTime<<"  "<<students[i].linesCode<<endl;
    }
*/

    while(1){
        int i;
        for(i=indx; i<N ; i++){
            if(students[i].submitTime <= currTime){
               studentsPQ.push(students[i]);
            }
            else{
               indx = i;
               break;
            }
        }

        if(i==N) indx = N;

        if(studentsPQ.empty() == true && indx != N){
           currTime = students[indx].submitTime;
        }
        else{
           Student largeCode = studentsPQ.top();
           totalTime = totalTime + (currTime + largeCode.linesCode - largeCode.submitTime);
           currTime += largeCode.linesCode;
           //cout<<studentsPQ.top().submitTime<<"   "<<studentsPQ.top().linesCode<<endl;
           studentsPQ.pop();
        }
        if(studentsPQ.empty() == true && indx == N) break; //if every student is checked and indx reached N, then break from while(1)
    }
    //cout<<totalTime/N<<endl;
    long long minimumAverageTime = totalTime/N;
    printf("%lld", minimumAverageTime);

    return 0;
}
