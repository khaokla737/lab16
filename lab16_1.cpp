#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *data,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << data[i];
        if(i % M == M - 1) cout << endl;
        else cout << " ";
    }
}

void randData(double *data,int N,int M){
    for(int i = 0; i < N*M; i++){
        data[i] = (double)(rand() % 101) / 100.0;
    }
}

void findRowSum(double *data, double sum1[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        sum1[i] = 0.0;
        for (int j = 0; j < m; j++)
        {
            sum1[i] += data[i * m + j];
        }
    }
}


void findColSum(double *data, double sum2[], int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        sum2[j] = 0.0;
        for (int i = 0; i < n; i++)
        {
            sum2[j] += data[i * m + j];
        }
    }
}

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}