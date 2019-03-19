#include <BinaryTree.hpp>
#include <Treap.hpp>

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

void semiRandomize(std::vector<int> *keys) {
    int N = keys->size();
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, N-1);
    for (int i = 0; i < N / 10; i++) {
        int a = distr(generator);
        int b = distr(generator);
        int keyA = (*keys)[a];
        int keyB = (*keys)[b];

        (*keys)[b] = keyA;
        (*keys)[a] = keyB;
    }
}

void randomize(std::vector<int> *keys) {
	std::random_shuffle(keys->begin(), keys->end());
        
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "./DSCompare <int>" << std::endl;
        return 0;
    }

    int N = 0;
    std::vector<int> keys_semi_ordered;
    std::vector<int> keys_random;

    std::vector<int> keys_search_existing;
    std::vector<int> keys_search_all;

    // Parse N
    N = std::atoi(argv[1]);
    std::cout << "Key count: " << N << std::endl;

    // Gera tilbúna lyklalista.
    std::cout << "Initialize key arrays." << std::endl;
    for (int i = 0; i < N; i++) {
        keys_semi_ordered.push_back(i*2 + 1);
        keys_random.push_back(i*2 + 1);
    }

    // Gera tilbúna leitarlista.
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> odds(0, N-1);
    std::uniform_int_distribution<int> odds_evens(0, (N-1)*2);
    for (int i = 0; i < N * 2; i++) {
        int randOdd = odds(generator) * 2 + 1;
        int randOddEven = odds_evens(generator);
        keys_search_existing.push_back(randOdd);
        keys_search_all.push_back(randOddEven);
    }


    semiRandomize(&keys_semi_ordered);
    randomize(&keys_random);

    // Setja upp gagnagrindur.
    BinaryTree binaryTree_random;
    BinaryTree binaryTree_semi_ordered;
	
	Treap treap_random;
    Treap treap_semi_ordered;

    using namespace std::chrono;
    
    /*
        Tímataka á innsetningum.
    */
    std::cout << "Timing: Insertions ---------------------------------------------------" << std::endl;

    auto start = high_resolution_clock::now();
    binaryTree_random.insert(&keys_random);
    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(stop - start);
    std::cout << "Binary Tree & Insert & Random & " << dur.count() << "us\\\\" << std::endl;
	//binaryTree_random.print();


    start = high_resolution_clock::now();
    binaryTree_semi_ordered.insert(&keys_semi_ordered);
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Binary Tree & Insert & Semi-Ordered & " << dur.count() << "us\\\\" << std::endl;
	//binaryTree_semi_ordered.print();
	
	start = high_resolution_clock::now();
	treap_random.insert(&keys_random);
	stop = high_resolution_clock::now();
	dur = duration_cast<microseconds>(stop - start);
	std::cout << "Treap & Insert & Random & " << dur.count() << "us\\\\" << std::endl;
	//treap_random.print();

    start = high_resolution_clock::now();
	treap_semi_ordered.insert(&keys_semi_ordered);
	stop = high_resolution_clock::now();
	dur = duration_cast<microseconds>(stop - start);
	std::cout << "Treap & Insert & Semi-ordered & " << dur.count() << "us\\\\" << std::endl;
	//treap_semi_ordered.print();


    /*
        Tímataka á leit.
    */

    std::cout << "Timing: Search -------------------------------------------------------" << std::endl;
    
    // BINARY TREE RANDOM
    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        binaryTree_random.find(keys_search_existing[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Binary Tree & Search & Random & Existing & " << dur.count() << "us\\\\" << std::endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        binaryTree_random.find(keys_search_all[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Binary Tree & Search & Random & All & " << dur.count() << "us\\\\" << std::endl;
    
    // BINARY TREE SEMI ORDERED
    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        binaryTree_semi_ordered.find(keys_search_existing[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Binary Tree & Search & Semi-Ordered & Existing & " << dur.count() << "us\\\\" << std::endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        binaryTree_semi_ordered.find(keys_search_all[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Binary Tree & Search & Semi-Ordered & All & " << dur.count() << "us\\\\" << std::endl;


    // Treap TREE RANDOM
    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        treap_random.find(keys_search_existing[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Treap & Search & Random & Existing & " << dur.count() << "us\\\\" << std::endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        treap_random.find(keys_search_all[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Treap & Search & Random & All & " << dur.count() << "us\\\\" << std::endl;
    
    // BINARY TREE SEMI ORDERED
    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        treap_semi_ordered.find(keys_search_existing[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Treap & Search & Semi-Ordered & Existing & " << dur.count() << "us\\\\" << std::endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < N * 2; i++) {
        treap_semi_ordered.find(keys_search_all[i]);
    }
    stop = high_resolution_clock::now();
    dur = duration_cast<microseconds>(stop - start);
    std::cout << "Treap & Search & Semi-Ordered & All & " << dur.count() << "us\\\\" << std::endl;

    return 0;
}
