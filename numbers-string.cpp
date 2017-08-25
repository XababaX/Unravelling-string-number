// exploring the number string problem from fivethirtyeight.com challenge
// https://fivethirtyeight.com/features/can-you-unravel-these-number-strings/
// XababaX 2017, using this problem to learn C++.
// Please send me comments and suggestions at xadbadbax 'at symbol' gmail 'dot' com

#include "header.hpp"

using namespace std;



// main
int main()
{
  int task = 2;
  // Uncomment lines below to offer option
  //cout<< "What task to execute?\n"<<"Choose 1 for single run, 2 for batch run.\n";
  //cin >> task;
  if (task ==1){
  int n, m, N;
  cout << "Chose first integer (base) <10:";
  cin >> n;
  cout << "Now chose second integer (delimitor) <10:";
  cin >> m;
  cout << "Now how many iterations?";
  cin >> N;
  cout << "building string with n= "<< n<<", m= " << m << ", N= " << N << ".\n";
  auto output = build(n,m,N);
  float numerator = count(output.begin(), output.end(), char(m) + '0');
  float denum = output.size();
  float ratio = numerator / denum;
  cout << "Ratio "<<  m << " over Total = " << ratio <<endl;}
  else
    {
      int n,m;
      int N=1000000;
      string output;
      cout << "n m r c"<< endl;
      for (int n=1; n<21; n++)
	{
	  for (int m=1; m<n; m++)
	    {
	      if (n!=0 &  m!=0)
		{
	      output = build(n,m,N);
	      float numer = count(output.begin(), output.end(), char(m)+'0');
	      float denum = output.size();
	      float ratio = numer/denum;
	      float corrected = (1.0 - ratio)/ratio;
	      cout << n << ' ' << m << ' ' << ratio << ' ' << corrected << endl;
		}
	    }
	}
      for (int n=1; n<21; n++)
        {
          for (int m=n+1; m<21; m++)
            {
              if (n!=0 &  m!=0)
                {
		  output = build(n,m,N);
		  float numer = count(output.begin(), output.end(), char(m)+'0');
		  float denum = output.size();
		  float ratio = numer/denum;
		  float corrected = (1.0 - ratio)/ratio;
		  cout << n << ' ' << m << ' ' << ratio << ' ' << corrected << endl;
                }
            }
        }


    }
  return 0;
}
