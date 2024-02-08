#include <iostream>
#include <deque>

using namespace std;

int N, K;
deque<int> durability;
deque<bool> conveyor;

void rotate(){
    conveyor.push_front(conveyor.back());
    conveyor.pop_back();
    
    durability.push_front(durability.back());
    durability.pop_back();
    
    conveyor[N-1] = false;
}

void move(){
    for(int i=N-2;i>=0;i--){
        if(conveyor[i] && !conveyor[i+1] && durability[i+1]>0){
            conveyor[i] = false;
            conveyor[i+1] = true;
            durability[i+1]--;
            if(durability[i+1]==0){
                K--;
            }
        }
    }
    conveyor[N-1] = false;
}

int main()
{
    cin >> N>>K;
    for(int i=0;i<2*N;i++){
        int a;
        cin>>a;
        durability.push_back(a);
        conveyor.push_back(false);
    }
    int answer = 0;
    while(K>0){
        rotate();
        move();
        if (!conveyor[0] && durability[0] > 0) {
			conveyor[0] = true;
			durability[0]--;
			if(durability[0]==0){
                K--;
            }
		}
        answer++;
    }
    cout<<answer;

    return 0;
}