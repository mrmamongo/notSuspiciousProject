#include <iostream>
#include <string>

struct player_rank {
    std::string name;
    int weight;
    bool EUW;

    explicit player_rank(
            std::string&& n = "",
            int w = -1,
            bool euw = false
                    ){
        name = n;
        weight = w;
        EUW = euw;
    }

    [[nodiscard]] std::string to_string() const {
        return name + "/" + std::to_string((weight + EUW) ? 2 : 0);
    }
    [[nodiscard]] bool empty() const {
        return weight == -1;
    }
};

class rank_repository {
public:
    player_rank* repository{};

    rank_repository(){
        repository = new player_rank[27];

        for (int i = 0; i < 27; ++i) {
            repository[i] = player_rank();
        }
    }

    void add(player_rank&& rank) const {
        for (int i = 0; i < 27; ++i) {
            if (repository[i].empty()) {
                repository[i] = rank;
                return;
            }
        }
    }

    [[nodiscard]] player_rank& get(int i) const {
        return repository[i];
    }
};

void fill_default_ranks(rank_repository& ranks)
{
    ranks.add(player_rank("Iron IV", 1));
    ranks.add(player_rank("Iron III", 1));
    ranks.add(player_rank("Iron II", 1));
    ranks.add(player_rank("Iron I", 1));
    ranks.add(player_rank("Bronze IV", 1));
    ranks.add(player_rank("Bronze III", 1));
    ranks.add(player_rank("Bronze II", 1));
    ranks.add(player_rank("Bronze I", 1));
    ranks.add(player_rank("Silver IV", 2));
    ranks.add(player_rank("Silver III", 2));
    ranks.add(player_rank("Silver II", 2));
    ranks.add(player_rank("Silver I", 2));
    ranks.add(player_rank("Gold IV", 3));
    ranks.add(player_rank("Gold III", 3));
    ranks.add(player_rank("Gold II", 4));
    ranks.add(player_rank("Gold I", 4));
    ranks.add(player_rank("Platinum IV", 5));
    ranks.add(player_rank("Platinum III", 5));
    ranks.add(player_rank("Platinum II", 6));
    ranks.add(player_rank("Platinum I", 6));
    ranks.add(player_rank("Diamond IV", 7, true));
    ranks.add(player_rank("Diamond III", 7, true));
    ranks.add(player_rank("Diamond II", 8, true));
    ranks.add(player_rank("Diamond I", 8, true));
    ranks.add(player_rank("Master", 9, true));
    ranks.add(player_rank("Grandmaster", 10, true));
    ranks.add(player_rank("Champion", 11, true));
}

int main(){
    rank_repository repository{};
    fill_default_ranks(repository);

    std::cout << "Hello, this is rank repository for League of legends!\n";
    std::cout << "Ranks:\n";
    for (int i = 0; i < 27; ++i) {
        std::cout << i << ": " << repository.get(i).name << '\n';
    }
    do {
        std::cout << "Choose rank to get info: \b";
        int index = 0;
        std::cin >> index;
        std::cout << index << ": " << repository.get(index).to_string() << '\n';
        std::cout << "continue? (y - yes, n - no): \b";
        char c;
        std::cin >> c;
        if ((c) != 'y') {
            std::cout << "Ok, goodbye!\n";
            break;
        }
    } while (true);
}
