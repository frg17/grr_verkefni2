#ifndef _SkipList_hpp_

#define _SkipList_hpp_
#include <vector>

#ifndef _Node_hpp_extra_
#define _Node_hpp_extra_
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;
#endif

/**
 * Tvíleitartré
 */
class SkipList {
    private:
        Node *root; //Rót trés.

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
