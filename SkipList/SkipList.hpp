#ifndef _SkipList_hpp_

#define _SkipList_hpp_
#include <vector>
#include <random>
#include <limits>

typedef struct SkipListNode {
    int key;
    struct SkipListNode *right;
    struct SkipListNode *down;
} SkipListNode;

/**
 * Tvíleitartré
 */
class SkipList {
    private:
		int size = 0;
		int nextSplit = 2;
		SkipListNode *head = NULL;
		SkipListNode *end = NULL;

        std::mt19937 generator;
	    std::uniform_int_distribution<int> distribution;

        const int MIN = std::numeric_limits<int>::min();
        const int MAX = std::numeric_limits<int>::max();

        bool flipCoin();
		SkipListNode *createNewChain();
		void addLevel();

		SkipListNode *down(SkipListNode *current, int key);

    public:
        /**
         * Smiður
         */
        SkipList();

        /**
         * Setur inn lykil í Tvíleitartré.
         * @param{int}{key} Lykill sem bætt er í tvíleitartréð.
         */
        void insert(int key);

        /**
         * Setur inn marga lykla í tvíleitartréð
         * @param{std::vector}{keys} Lyklar sem eiga að fara í tréð.
         */  
        void insert(std::vector<int> *keys);

        /**
         * Finnur lykil í tvíleitartrénu.
         * @param{int}{key} Lykillinn sem á að finna.
         */
        bool find(int key) const;

	void print();
};

#endif
