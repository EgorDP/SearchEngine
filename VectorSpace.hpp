#ifndef VECTOR_H
#define VECTOR_H
#include<tuple>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

class Document{
    public:
        vector<int> counts; // Counts of the term spaces appearing in this document
        string name;        // Name of the document

        /**
         * Constructor to set document name
         * @param string name of the document
         */
        Document(string n){
            name = n;
        }
        /**
         * Calculate the magnitude of the given vector
         * @throws IllegalArgumentException if counts has not been filled 
         */
        // double calcMagnitude(vector<int> vec);

        /**
         * Calculate the angle between the query vector and counts (query and counts should have the same dimension)
         * @param query  Search terms
         */
        double calcAngle(vector<int> query);

        /**
         * TEST method to add your own counts
         */
        void addCounts(vector<int> counts);
};

#endif