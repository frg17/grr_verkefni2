#ifndef _Treap_hpp_

#define _Treap_hpp_
#include <vector>
#include <random>


typedef struct TreapNode {
    int key;
	int priority;
    struct TreapNode *left;
    struct TreapNode *right;
} TreapNode;



/**
 * Tvíleitartré
 */
class Treap {
    private:
        TreapNode *root; //Rót trés.
		std::mt19937 generator;
	    std::uniform_int_distribution<int> distribution;
		TreapNode *newNode(int key);
    
    public:
        /**
         * Smiður
         */
        Treap();

        /**
         * Setur inn lykil í Treap
         * @param{int}{key} Lykill sem bætt er í treap
         */
        void insert(int key);

        /**
         * Setur inn marga lykla í Treap
         * @param{std::vector}{keys} Lyklar sem eiga að fara í tréð.
         */  
        void insert(std::vector<int> *keys);

        /**
         * Finnur lykil í Treap
         * @param{int}{key} Lykillinn sem á að finna.
         */
        bool find(int key) const;

	void print();
};

#endif
