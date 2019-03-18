#ifndef _BinaryTree_hpp_

#define _BinaryTree_hpp_
#include <vector>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;


/**
 * Tvíleitartré
 */
class BinaryTree {
    private:
        Node *root; //Rót trés.

    public:
        /**
         * Smiður
         */
        BinaryTree();

        /**
         * Setur inn lykil í Tvíleitartré.
         * @param{int}{key} Lykill sem bætt er í tvíleitartréð.
         */
        void insert(int key);

        /**
         * Setur inn marga lykla í tvíleitartréð
         * @param{std::vector}{keys} Lyklar sem eiga að fara í tréð.
         */  
        void insert(std::vector<int> keys);

        /**
         * Finnur lykil í tvíleitartrénu.
         * @param{int}{key} Lykillinn sem á að finna.
         */
        bool find(int key);
};

#endif