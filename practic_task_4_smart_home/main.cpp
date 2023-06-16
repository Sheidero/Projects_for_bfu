#include <iostream>

class Device{
private:
    std::string m_name;
public:
    explicit Device(const std::string& name){
        m_name = name;
    }
    void poll(){
        std::cout << "Device name - " << m_name << std::endl;
    }
};

class CounterElectricEnergy : public Device{
public:
    explicit CounterElectricEnergy(const std::string& name): Device(name) {}
};

class BlockInsertDiscretSignal : public Device{
private:
    /* data */
public:
    explicit BlockInsertDiscretSignal(const std::string& name): Device(name) {}
};

class BlockControlHeat : public Device{
private:
    /* data */
public:
    explicit BlockControlHeat(const std::string& name): Device(name) {}
};

int main(){
    
    return 0;
}