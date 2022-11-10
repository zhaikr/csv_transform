
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>

using namespace std;

int main()
{
  //time_t t = time(0);
  //tm* now = localtime(&t);
  //cout << now->tm_hour << ':' << now->tm_min << endl;
  ifstream in_file;
  ofstream out_file;
  out_file.open("csv_transform.csv", ios::app);
  if (!out_file.is_open())
  {
    cout << "保存文件错误，需要检查";
  }
  in_file.open("..//BG_Huashang_dir90_L1_Xr0.006731_Yr0.004_C1728_R5000.csv", ios::in);
  string line_str;
  if (!in_file.is_open())
  {
    cout << "打开文件失败";
  }
  vector<vector<string>> str_array;
  vector<string> line_array;
  int count = 0;
  cout << "开始运行" <<endl;
  //读取文件
  while(getline(in_file, line_str))
  {
    ++count;

    //cout << line_str << endl;
    stringstream ss(line_str);
    string str;

    while (getline(ss, str, ','))
    {
      line_array.emplace_back(str);
    }

    if(count % 1728 == 0)
    {
      count = 0;
      str_array.emplace_back(line_array);
      //line_array.clear();
      vector<string>().swap(line_array);
    }
  }

  //写入文件
  for (auto& str : str_array)
  {
    for (auto& s : str)
    {
      out_file << s << ',';
    }
    out_file << endl;
  }
  in_file.close();
  out_file.close();
  cout << "结束运行" <<endl;
  //cout << now->tm_hour << ':' << now->tm_min << endl;
  return 0;
}

