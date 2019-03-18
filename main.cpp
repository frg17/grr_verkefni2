#include <BinaryTree.hpp>

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

void semiRandomize(std::vector<int> *keys) {
    int N = keys->size();
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, N);
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

    // Parse N
    N = std::atoi(argv[1]);
    std::cout << "Key count: " << N << std::endl;

    // Gera tilbúna lyklalista.
    std::cout << "Initialize key arrays." << std::endl;
    for (int i = 0; i < N; i++) {
        keys_semi_ordered.push_back(i*2 + 1);
        keys_random.push_back(i*2 + 1);
    }

    semiRandomize(&keys_semi_ordered);
    randomize(&keys_random);

    // Setja upp gagnagrindur.
    BinaryTree binaryTree_random;
    BinaryTree binaryTree_semi_randomized;

    //Tímasetja innsetningar.
    using namespace std::chrono;
    
    auto start = high_resolution_clock::now();
    binaryTree_random.insert(keys_random);
    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<nanoseconds>(stop - start);
    std::cout << "Binary Tree & Insert & Random & " << dur.count() << "us" << std::endl;

    start = high_resolution_clock::now();
    binaryTree_semi_randomized.insert(keys_semi_ordered);
    stop = high_resolution_clock::now();
    dur = duration_cast<nanoseconds>(stop - start);
    std::cout << "Binary Tree & Insert & Semi-Ordered & " << dur.count() << "us" << std::endl;


    return 0;
}