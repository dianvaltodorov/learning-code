#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>

using namespace std;


struct Student
{

  int age;
  int height;
  int fn;
  Student(int age, int height, int fn) : age(age), height(height), fn(fn){};
};

bool agecompare(Student a, Student b) { return a.age < b.age;}
bool heightcompare(Student a, Student b) { return a.height < b.height;}
bool fncompare(Student a, Student b) { return a.fn < b.fn;}


int main()
{
  vector<Student> vec;
  vec.push_back(Student(19, 182, 61791));
  vec.push_back(Student(20, 172, 61635));
  vec.push_back(Student(21, 183, 61624));
  vec.push_back(Student(20, 162, 61653));
  vec.push_back(Student(19, 189, 63467));
  vec.push_back(Student(21, 175, 61346));
  vec.push_back(Student(23, 172, 56136));
  vec.push_back(Student(20, 178, 34663));
  vec.push_back(Student(24, 189, 64313));

  sort(vec.begin(), vec.end(), agecompare);
  for(int i = 0 ; i < vec.size(); i++)
  {
    printf("%d %d %d\n", vec[i].age, vec[i].height, vec[i].fn);
  }

  sort(vec.begin(), vec.end(), heightcompare);
  for(int i = 0 ; i < vec.size(); i++)
  {
    printf("%d %d %d\n", vec[i].age, vec[i].height, vec[i].fn);
  }

  sort(vec.begin(), vec.end(), fncompare);
  for(int i = 0 ; i < vec.size(); i++)
  {
    printf("%d %d %d\n", vec[i].age, vec[i].height, vec[i].fn);
  }
  printf("\n");
  return 0;
}
