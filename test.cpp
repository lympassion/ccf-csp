#include <cstdio>
#include <vector>

using namespace std;

vector<int> seats(20,5);

void printSeats(int row, int num) {
    for(int i=1; i<=num; i++) {
        printf("%d ", row*5+i+5-seats[row]);
    }
}

void requstSeats(int num) {
    for(int i=0; i<20; i++) {
        if(seats[i] >= num) {
            printSeats(i, num);
            seats[i] -= num;
            num = 0;
        }
    }
    int i = 0;
    while(num) {
        if(seats[i] > 0) {
            if(num <= seats[i]) {
                printSeats(i, num);
                num = 0;
                seats[i] -= num;
            }
            else {
                printSeats(i, seats[i]);
                num -= seats[i];
                seats[i] = 0;
            }
        }
        i++;
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    
    int req;
    for(int n=0; n<N; n++) {
        scanf("%d", &req);
        requstSeats(req);
    }
}