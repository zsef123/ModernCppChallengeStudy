#include <gsl/gsl>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
/*
// Tabular printing of a list of processes
chrome.exe 1044 Running marius.bancila 25180 32-bit
chrome.exe 10100 Running marius.bancila 227756 32-bit
cmd.exe 512 Running SYSTEM 48 64-bit
explorer.exe 7108 Running marius.bancila 29529 64-bit
skype.exe 22456 Syspended marius.bancila 65664 64-bit
*/

uint32_t get_max_len(std::vector<std::string> vec){
    uint32_t len = 0;
    for (auto i : vec)
        len = (len < i.length()) ? i.length() : len;
    return len;
}

std::string n_space(const uint32_t n) {
    char tmp[n + 1];
    for (int i = 0 ; i< n; i++)
        tmp[i] = ' ';
    tmp[n] = 0;

    std::string out = tmp;
    return out;
} 

class Proc {
    private:
        uint32_t idx;
        std::vector<std::string> name;
        std::vector<std::string> pid;
        std::vector<std::string> status;
        std::vector<std::string> owner;
        std::vector<std::string> mem;
        std::vector<std::string> bits;

    public:
        Proc(const uint32_t n=5) :
            idx(n),
            name(n),
            pid(n),
            status(n),
            owner(n),
            mem(n),
            bits(n)
        {}
        
        void push(std::string name, uint32_t pid, std::string status, std::string owner, uint32_t mem, uint32_t bits) {
            this->name.push_back(name);
            this->pid.push_back(std::to_string(pid));
            this->status.push_back(status);
            this->owner.push_back(owner);
            this->mem.push_back(std::to_string(mem));
            this->bits.push_back(std::to_string(bits) + "-bit");
        }

        void print_out(bool kbit=false) {
            uint32_t name_len = get_max_len(name);
            uint32_t pid_len = get_max_len(name);
            uint32_t status_len = get_max_len(status);
            uint32_t owner_len = get_max_len(owner);
            uint32_t mem_len = get_max_len(mem);
            uint32_t bits_len = get_max_len(bits);

            std::string output = "";
            for (uint32_t i = 0 ; i < this->idx ; i++) {
                output += name[i]   + n_space(name_len   - name[i].length()); 
                std::cout << "name " << name[i];
                output += pid[i]    + n_space(pid_len    - pid[i].length());
                output += status[i] + n_space(status_len - status[i].length());
                output += owner[i]  + n_space(pid_len    - owner[i].length());
                /*
                uint32_t mem_i = std::stoi(mem[i]);
                if (kbit)
                    mem_i /= 1024;
                std::string mem_s = std::to_string(mem_i);

                output += n_space(mem_len - mem_s.length()) + mem_s + " ";
                */
                output += n_space(mem_len - mem[i].length()) + mem[i] + " ";

                output += bits[i]   + n_space(bits_len   - bits[i].length());
                output += "\n";
            }
            std::cout << output;
        }
};

int main(int argc, char *argv[]) {
    Proc proc(5);
    proc.push("chrome.exe", 10444, "Running", "marius.bancila", 25180, 32);
    proc.push("chrome.exe", 10100, "Running", "marius.bancila", 227756, 32);
    proc.push("cmd.exe", 512, "Running", "marius.bancila", 58, 64);
    proc.push("explore.exe", 7108, "Running", "marius.bancila", 29529, 64);
    proc.push("skype.exe", 22456, "Running", "marius.bancila", 65654, 64);
    proc.print_out(true);
  return 0;
}