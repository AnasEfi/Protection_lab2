
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

void lengh_key(vector<unsigned char> word, int N);

void lengh_key (vector<unsigned char> word,int N)
{
    int count = 0;
    vector<double> frequencies;
    vector<double> number;
    for (int i = 0; i < word.size();i++)
    {
        number.clear();
        int key_length = i;
        for (int k = 0; k <= key_length; k++) //одно слово
        {
            for (int j = word.size(); j > 0; j--) //одна буква проверяется со всем словом
            {
                bool check = 0;
                for (int h = 0; h<k; h++)
                {
                    if (word[k] == word[h])
                    {
                        check = 1;
                        break;
                    }
                }
                if ((word[k] == word[word.size() - j])&&(!check)) //число повторений одного символа 
                {
                    count++;
                }
            }
            number.push_back(count);
            //cout << k << ": " << number[k] << endl;;
            count = 0;
        }
        cout <<endl << "vector" << endl;
       for (auto v : number)
            cout << v << " ";
            double index_s = 0;
            double sum = 0;
            for (auto v : number)
            {
                index_s = (v * (v - 1)) / (N * (N - 1));
                sum = sum + index_s;
            }
            frequencies.push_back(sum);
    }
    int num = 1;
    for (auto v : frequencies)
    {
        cout <<'\n' << num << ":" << ' ' << v << endl;
        num++;
    }

    sort(frequencies.begin(), frequencies.end());
    for (auto v : frequencies)
    {
        cout << num << ":" << ' ' << v << endl;
    }
    
  /*  sort(frequencies.begin(), frequencies.end());
    for (auto v : frequencies)
    {
        cout << num << ":" << ' ' << v << endl;
    }*/
}

int main()
{
    /*ifstream in("datatest.txt", ios::binary);
    vector<char> v ((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());*/

    vector<unsigned char> v;
    ifstream inf("test.txt", ios::in);
    string count,word;
    word = "";
    while (!inf.eof())
    {
        getline(inf, count);
        word += count;
    }
    inf.close();
    for (int i = 0;i < word.length();i++)
    {
        v.push_back(word[i]);
    }
    lengh_key(v,word.size());
    return 0;
}
