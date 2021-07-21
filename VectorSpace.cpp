#include "VectorSpace.hpp"
#include "Binary.hpp"
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>
using namespace std;    


double calcMagnitude(vector<int> & vec){
    long long sum = 0;
    for(int term: vec){
        sum += pow(term,2);
    }
    return sqrt(sum);
}

double Document::calcAngle(vector<int> query){
    double dot_product = 0; 
    for(int i = 0; i < (int)query.size(); ++i){
        dot_product += query[i] * counts[i];
    }
    double magnitude = calcMagnitude(query) * calcMagnitude(counts);
    return dot_product / magnitude;
}



// https://www.quora.com/How-can-I-read-multiple-files-in-C++-in-the-same-program
void run_with(const char* filename) { 
  std::ifstream fi(filename); 
  std::string s; 
  fi >> s; 
  std::cout << filename << " : " << s << std::endl; 
} 
void run_all(int argc, char** &argv){
    for (int i = 1; i < argc; ++i) { 
        run_with(argv[i]); 
    } 
}
void first_read(int & argc, char* argv[]){
    string word;
    string line;
    for(int i = 1; i < argc; ++i){
        string fileName = argv[i];
        ifstream reader(fileName);
        if(!reader){
            cout << "Input file error\n";
            return;
        }
        
        // for(int c = 0; !reader.eof(); ++c){
        //     reader.get(letter);
        //     if(reader.fail()){
        //         break;
        //     }
        //     cout << letter;
        // }

        vector<string> stopWords = {"a","about","above","after","again","against","all","am","an","and","any","are","as","at","be","because","been","before","being","below","between","both","but","by","can","did","do","does","doing","don","down","during","each","few","for","from","further","had","has","have","having","he","her","here","hers","herself","him","himself","his","how","i","if","in","into","is","it","its","itself","just","me","more","most","my","myself","no","nor","not","now","of","off","on","once","only","or","other","our","ours","ourselves","out","over","own","s","same","she","should","so","some","such","t","than","that","the","their","theirs","them","themselves","then","there","these","they","this","those","through","to","too","under","until","up","very","was","we","were","what","when","where","which","while","who","whom","why","will","with","you","your","yours","yourself","yourselves"};
        vector<string> punctuation = {".",",","!","?"};
        while(reader >> word){
            // if(search(stopWords, (string)word.back()) ){

            // }
            if(search(stopWords, word)){
                // Do not include it
            }else {
                cout << word << "|";
            }
            
        }
        reader.close();        
        
    }
    cout << "\nEND\n";
}   

int main(int argc, char* argv[]){
    first_read(argc,argv);
}