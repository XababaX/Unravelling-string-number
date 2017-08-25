#include <iostream>
#include<string>
#include<vector>
using namespace std;
// to do: define string2vector, vector2string

const string initial = "33323332333233233323332333233233323332";
string vector2string(vector<int> vIn)
{
  vector<int>::iterator it= vIn.begin();
  int s = vIn.size();
  string output ("");
  for(int i = 0; i<s; i++)
  {
    output.resize(1+i,*it+'0');
    it++;
  }
  return output;
}

vector<int> string2vector(string sIn)
{
  vector<int> output;
  int sz = sIn.size();
  for (int i=0; i<sz; i++)
  {
    //cout << "Step: " << i << ", adding " << sIn[i]  <<  " to vector.\n";
    output.push_back((int) sIn[i] - 48);
  }
  return output;
}

// Task 0: testing                                                              
void fun_task0()
{
  vector<int> temp = string2vector(initial);
  //cout << "test of convertors : " << vector2string(temp)<< endl;              
  for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
    {
      cout << *it;
    }
}

// Task 1:  build extend string to order N                                      
string extend(int N)
{
  // If the initial string is not selfconsistent or doesnt end in 2, this will \
not work                                                                        
  if(initial.back() != '2')
    {
      cout<<"Please provide initial string that ends in a 2 and is self-consist\
ent" << endl;
      return "Error";
    }

// convert to vector and extend starting at digit that built last '3..2' bloc\
k                                                                               
  vector<int> vec_string = string2vector(initial);
 int start = count(initial.begin(), initial.end(), '2');
 // if only one '2', then count will return 1, and we will start vector[1] as \
desired                                                                         
  for(int j=0; j<N; j++)
    {
      vector<int>::iterator it = vec_string.begin()+start+j;
      //add the next block of '3..2'                                              
      /*for (int i = 0; i<*it; i++)                                               
      {                                                                         
        vec_string.push_back(3);                                                
        }*/
      vector<int> vec_append;
      vec_append.assign(*it,3);
      vec_append.push_back(2);
      vec_string.insert(vec_string.end(), vec_append.begin(), vec_append.end());
      //cout << "vector size is now " << vec_string.size()<<endl;                 
      //cout << "Step j = " << j << " with value " << *it << '\n';                
    }
 return vector2string(vec_string);
}



// Task 2: build the string for arbitrary n and m (except 1,1)                  
string build(int n, int m, int N)
{
  // special cases where the string cannot be built n=m or n=0 or m=0           
  if(n==m)
    {
      cout << "n=m is a combination that is not permitted\n"<<endl;
      return "Error: n=m\n";
    }
  else if (n==0 || m==0 || N==0)
    {cout << "N, n and m must be positive\n";
      return "Error: N or n or m null\n";
    }
  // now onto building string for other cases                                   

  // start off with n                                                           
  vector<int> vec_init, vec_append;
  vec_init.assign(n, n);
  vec_init.push_back(m);
  /*  for (vector<int>::iterator at = vec_init.begin(); at < vec_init.end(); at\
++)                                                                             
    {                                                                           
    cout << *at;                                                              
    }                                                                           
    cout <<endl;                                                                  
  */
  // extend string N times                                                      
  for(int j=1; j<N; j++)
    {
      vector<int>::iterator it = vec_init.begin()+j-1;
      //cout << "step j= " << j << ", adding a block of "<< *it << ".\n";       
      //add the next block n...nm                                               
      vec_append.assign(*it, n);
      vec_append.push_back(m);
      vec_init.insert(vec_init.end(), vec_append.begin(), vec_append.end());
      //cout << "vector size is now " << vec_string.size()<<endl;               
    }
  // return converted string                                                    
  return vector2string(vec_init);
}
