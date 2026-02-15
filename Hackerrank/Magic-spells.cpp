#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    if (Fireball* f = dynamic_cast<Fireball*>(spell)) {
        f->revealFirepower();
    }
    else if (Frostbite* f = dynamic_cast<Frostbite*>(spell)) {
        f->revealFrostpower();
    }
    else if (Thunderstorm* f = dynamic_cast<Thunderstorm*>(spell)) {
        f->revealThunderpower();
    }
    else if (Waterbolt* f = dynamic_cast<Waterbolt*>(spell)) {
        f->revealWaterpower();
    }
    else {
        string s = spell->revealScrollName();
        string t = SpellJournal::read();

        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[m][n] << endl;
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}

//Editorial
//This question uses dp to solve the last part where the spell is not found, we construct a grid from 0 to length of s and from 0 to length of j called dp.
//Then, dp[i][j] is the maximum subsequence from s[0] to s[i - 1] and likewise for t except using j, the rows and columns dp[i][0] and dp[0][j] are all 0
//to show comparisons between an empty string. Then, we compare the value of one character from s to every other character in t to find matches, if a match
//is found, then any common subsequence from earlier prefixes can be extended by this character, we want the longest so we will choose the best which is 
//(i-1, j-1) plus the matching character for the current cell, That’s why we go diagonally and add 1. If a match isn't found, we cannot keep both subsequences
//so we must drop 1, to choose which one, we have to choose the best subsequence which can be determined by comparing dp[i-1][j], dp[i][j-1], one is the largest
//subsequence from s[0] to s[i - 2] and t[0] to t[j - 1] while the other is from s[0] to s[i - 1] and t[0] to t[j - 2]. So obviously, we will choose the largest
//subsequence between the two of them e.g. s = "abeed" and t = "abued", at the letter e (index = 3), we will take max subsequence between s[0] to s[2] and 
//between t[0] to t[3], this will give us a length of 3 as opposed to 2 when comparing it the other way around.
