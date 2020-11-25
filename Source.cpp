// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double P0(const int K, const int N)
{
	double D = 1;
	for (int i = K; i <= N; i++)
	{
		D *= (sin(i) * sin(i) + cos(1 / i) * cos(1 / i)) / pow(i, 2);
	};
	return D;
}
double P1(const int K, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return ((sin(i) * sin(i) + cos(1 / i) * cos(1 / i)) / pow(i, 2)) + P1(K, N, i + 1);
}
double P2(const int K, const int N, const int i)
{
	if (i < K)
		return 0;
	else
		return (sin(i) * sin(i) + cos(1 / i) * cos(1 / i)) / pow(i, 2) + P2(K, N, i - 1);
}
double P3(const int K, const int N, const int i, double t)
{
	t = t + (sin(i) * sin(i) + cos(1 / i) * cos(1 / i)) / pow(i, 2);
	if (i >= N)
		return t;
	else
		return P3(K, N, i + 1, t);
}
double P4(const int K, const int N, const int i, double t)
{
	t = t + (sin(i) * sin(i) + cos(1 / i) * cos(1 / i)) / pow(i, 2);
	if (i <= K)
		return t;
	else
		return P4(K, N, i - 1, t);
}
int main()
{
	int K = 1, 
		N = 15;
	cout << "(iter) S0 = " << P0(K, N) << endl;
	cout << "(rec up ++) S1 = " << P1(K, N, K) << endl;
	cout << "(rec up --) S2 = " << P2(K, N, N) << endl;
	cout << "(rec down ++) S3 = " << P3(K, N, K, 0) << endl;
	cout << "(rec down --) S4 = " << P4(K, N, N, 0) << endl;
	return 0;
}