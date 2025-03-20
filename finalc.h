#include <iostream>
#include <vector>
class Whole;
class Decimal;
class BOOL;
class CPU;
class Memory;

extern CPU cpu; 
extern Memory mem;

class Memory
{
private:
    std::vector<Whole> wholeMemory;
    std::vector<Decimal> decimalMemory;
    std::vector<BOOL> boolMemory;

public:
    Memory(std::vector<Whole> wholeMemory, std::vector<Decimal> decimalMemory, std::vector<BOOL> boolMemory) : wholeMemory(wholeMemory), decimalMemory(decimalMemory), boolMemory(boolMemory) {}
    Memory() {}
    Whole getWholeMemory(int location);
    Decimal getDecimalMemory(int location);
    BOOL getBoolMemory(int location);
    void setWholeMemory(std::vector<Whole> wMemory) { wholeMemory = wMemory; }
    void setDecimalMemory(std::vector<Decimal> dMemory) { decimalMemory = dMemory; }
    void setBoolMemory(std::vector<BOOL> bMemory) { boolMemory = bMemory; }
    void allocateWholeMemory(Whole &whole) { wholeMemory.push_back(whole); } 
    void allocateDecimalMemory(Decimal &dec) { decimalMemory.push_back(dec); }
    void allocateBoolMemory(BOOL &bol) { boolMemory.push_back(bol); }
    int boolMemorySize() { return boolMemory.size(); }
    int wholeMemorySize() { return wholeMemory.size(); }
    int decimalMemorySize() { return decimalMemory.size(); }
};
Memory mem;

class CPU
{
private:
    std::vector<Whole> wholeAccumulator;
    std::vector<Decimal> decimalAccumulator;
    std::vector<BOOL> boolAccumulator;

public:
    CPU() {}

    void loadWhole(int location);
    void loadDecimal(int location);
    void loadBool(int location);

    void store(Memory &memory);
    void addWhole();
    void subWhole();
    void mulWhole();
    void divWhole();
    void compWhole();
    void anddWhole();
    void orrWhole();
    void nottWhole();
    void greaterWhole();
    void lessWhole();
    void greaterOrWhole();
    void lessOrWhole();
    
    void addDecimal();
    void subDecimal();
    void mulDecimal();
    void divDecimal();
    void compDecimal();
    void anddDecimal();
    void orrDecimal();
    void nottDecimal();
    void greaterDecimal();
    void lessDecimal();
    void greaterOrDecimal();
    void lessOrDecimal();
    
    void compBool();
    void anddBool();
    void orrBool();
    void nottBool();
    void greaterBool();
    void lessBool();
 	void greaterOrBool();
    void lessOrBool();

    std::vector<Whole> getWholeAccumulator() { return wholeAccumulator; }
    std::vector<Decimal> getDecimalAccumulator() { return decimalAccumulator; }
    std::vector<BOOL> getBoolAccumulator() { return boolAccumulator; }
};
CPU cpu;

class Whole
{
private:
    int value;
    int location;
    static int lastLocation;

public:
    Whole() : value(0), location(0) {}

    Whole(int value)
    {
        this->value = value;
        mem.allocateWholeMemory(*this); //chat helped me get the correct refrence
        this->location = mem.wholeMemorySize() - 1;
        lastLocation++;
    }

    int getValue() { return value; }

    Whole operator+(Whole &other) const;
    Whole operator-(Whole &other) const;
    Whole operator*(Whole &other) const;
    Whole operator/(Whole &other) const;
    Whole operator==(Whole &other) const;
    bool operator&&(Whole &other) const;
    bool operator||(Whole &other) const;
    bool operator!=(Whole &other) const;
    bool operator>(Whole &other) const;
    bool operator<(Whole &other) const;
    bool operator>=(Whole &other) const;
    bool operator<=(Whole &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Whole &whole)
    {
        os << whole.value;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Whole &whole)
    {
        is >> whole.value;
        return is;
    }
};

class Decimal
{
private:
    float value;
    int location;
    static int lastLocation;

public:
    Decimal() : value(0), location(0) {}

    Decimal(float value)
    {
        this->value = value;
        mem.allocateDecimalMemory(*this);
        this->location = mem.decimalMemorySize() - 1;
        lastLocation++;
    }

    float getValue() { return value; }

    Decimal operator+(Decimal &other) const;
    Decimal operator-(Decimal &other) const;
    Decimal operator*(Decimal &other) const;
    Decimal operator/(Decimal &other) const;
    Decimal operator==(Decimal &other) const;
    bool operator&&(Decimal &other) const;
    bool operator||(Decimal &other) const;
    bool operator!=(Decimal &other) const;
    bool operator>(Decimal &other) const;
    bool operator<(Decimal &other) const;
    bool operator>=(Decimal &other) const;
    bool operator<=(Decimal &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Decimal &dec)
    {
        os << dec.value;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Decimal &dec)
    {
        is >> dec.value;
        return is;
    }
};

class BOOL
{
private:
    bool value;
    int location;
    static int lastLocation;

public:
    BOOL() : value(0), location(0) {}

    BOOL(bool value)
    {
        this->value = value;
        mem.allocateBoolMemory(*this);
        this->location = mem.boolMemorySize() - 1;
        lastLocation++;
    }

    bool getValue() { return value; }

    
    BOOL operator==(BOOL &other) const;
    bool  operator>(BOOL &other) const;
    bool operator<(BOOL &other) const;
    bool operator&&(BOOL &other) const;
    bool operator||(BOOL &other) const;
    bool operator!=(BOOL &other) const;
    bool  operator>=(BOOL &other) const;
    bool  operator<=(BOOL &other) const;


    friend std::ostream &operator<<(std::ostream &os, const BOOL &Bool)
    {
        os << Bool.value;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, BOOL &Bool)
    {
        is >> Bool.value;
        return is;
    }
};

int Whole::lastLocation = 0;
int Decimal::lastLocation = 0;
int BOOL::lastLocation = 0;

Whole Memory::getWholeMemory(int location)
{
    return wholeMemory[location];
}

Decimal Memory::getDecimalMemory(int location)
{
    return decimalMemory[location];
}

BOOL Memory::getBoolMemory(int location)
{
    return boolMemory[location];
}

void CPU::loadWhole(int location)
{
    wholeAccumulator.push_back(mem.getWholeMemory(location));
}

void CPU::loadDecimal(int location)
{
    decimalAccumulator.push_back(mem.getDecimalMemory(location));
}

void CPU::loadBool(int location)
{
    boolAccumulator.push_back(mem.getBoolMemory(location));
}

void CPU::store(Memory &memory)
{
    memory.allocateWholeMemory(wholeAccumulator.back()); //google said to use the .back() when trying to find last element
    memory.allocateDecimalMemory(decimalAccumulator.back());
    memory.allocateBoolMemory(boolAccumulator.back());
}

void CPU::addWhole()
{
    Whole x = wholeAccumulator[0]; //chat showed me how to get the correct index
    Whole y = wholeAccumulator[1];
    int result = x.getValue() + y.getValue();
    wholeAccumulator.push_back(Whole(result)); 
}

void CPU::greaterWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    bool result = x.getValue() > y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::lessWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    bool result = x.getValue() < y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::greaterOrWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    bool result = x.getValue() >= y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::lessOrWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    bool result = x.getValue() <= y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::subWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    int result = x.getValue() - y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::mulWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    int result = x.getValue() * y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::divWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    int result = x.getValue() / y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::anddWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    bool result = x.getValue() && y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::orrWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    bool result = x.getValue() || y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::nottWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    bool result = x.getValue() != y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::compWhole()
{
    Whole x = wholeAccumulator[0];
    Whole y = wholeAccumulator[1];
    int result = x.getValue() == y.getValue();
    wholeAccumulator.push_back(Whole(result));
}

void CPU::addDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    float result = x.getValue() + y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::subDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    float result = x.getValue() - y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::mulDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    float result = x.getValue() * y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::divDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    float result = x.getValue() / y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::anddDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() && y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::orrDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() || y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::nottDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() != y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::compDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    float result = x.getValue() == y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::greaterDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() > y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::lessDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() < y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::greaterOrDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() >= y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::lessOrDecimal()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() <= y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}

void CPU::anddBool()
{
    BOOL x = boolAccumulator[0];
    BOOL y = boolAccumulator[1];
    bool result = x.getValue() && y.getValue();
    boolAccumulator.push_back(BOOL(result));
}

void CPU::orrBool()
{
    BOOL x = boolAccumulator[0];
    BOOL y = boolAccumulator[1];
    bool result = x.getValue() || y.getValue();
    boolAccumulator.push_back(BOOL(result));
}

void CPU::nottBool()
{
    BOOL x = boolAccumulator[0];
    BOOL y = boolAccumulator[1];
    bool result = x.getValue() != y.getValue();
    boolAccumulator.push_back(BOOL(result));
}

void CPU::compBool()
{
    BOOL x = boolAccumulator[0];
    BOOL y = boolAccumulator[1];
    bool result = x.getValue() == y.getValue();
    boolAccumulator.push_back(BOOL(result));
}

void CPU::greaterBool()
{
    BOOL x = boolAccumulator[0];
    BOOL y = boolAccumulator[1];
    bool result = x.getValue() > y.getValue();
    boolAccumulator.push_back(BOOL(result));
}

void CPU::lessBool()
{
    BOOL x = boolAccumulator[0];
    BOOL y = boolAccumulator[1];
    bool result = x.getValue() < y.getValue();
    boolAccumulator.push_back(BOOL(result));
}

void CPU::greaterOrBool()
{
    BOOL x = boolAccumulator[0];
    BOOL y = boolAccumulator[1];
    bool result = x.getValue() >= y.getValue();
    boolAccumulator.push_back(BOOL(result));
}

void CPU::lessOrBool()
{
    Decimal x = decimalAccumulator[0];
    Decimal y = decimalAccumulator[1];
    bool result = x.getValue() <= y.getValue();
    decimalAccumulator.push_back(Decimal(result));
}



Whole Whole::operator+(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.addWhole();
    return cpu.getWholeAccumulator().back();
}

Whole Whole::operator-(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.subWhole();
    return cpu.getWholeAccumulator().back();
}

Whole Whole::operator*(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.mulWhole();
    return cpu.getWholeAccumulator().back();
}

Whole Whole::operator/(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.divWhole();
    return cpu.getWholeAccumulator().back();
}

Whole Whole::operator==(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.compWhole();
    return cpu.getWholeAccumulator().back();
}

bool Whole::operator&&(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.anddWhole();
    return cpu.getWholeAccumulator().back().getValue();
}

bool Whole::operator||(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.orrWhole();
    return cpu.getWholeAccumulator().back().getValue();
}

bool Whole::operator!=(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.nottWhole();
    return cpu.getWholeAccumulator().back().getValue();
}

bool Whole::operator>(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.greaterWhole();
    return cpu.getWholeAccumulator().back().getValue();
}

bool Whole::operator<(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.lessWhole();
    return cpu.getWholeAccumulator().back().getValue();
}

bool Whole::operator>=(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.greaterOrWhole();
    return cpu.getWholeAccumulator().back().getValue();
}

bool Whole::operator<=(Whole &other) const
{
    cpu.loadWhole(location);
    cpu.loadWhole(other.location);
    cpu.lessOrWhole();
    return cpu.getWholeAccumulator().back().getValue();
}

Decimal Decimal::operator+(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.addDecimal();
    return cpu.getDecimalAccumulator().back();
}

Decimal Decimal::operator-(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.subDecimal();
    return cpu.getDecimalAccumulator().back();
}

Decimal Decimal::operator*(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.mulDecimal();
    return cpu.getDecimalAccumulator().back();
}

Decimal Decimal::operator/(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.divDecimal();
    return cpu.getDecimalAccumulator().back();
}

Decimal Decimal::operator==(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.compDecimal();
    return cpu.getDecimalAccumulator().back();
}

bool Decimal::operator&&(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.anddDecimal();
    return cpu.getDecimalAccumulator().back().getValue();
}

bool Decimal::operator||(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.orrDecimal();
    return cpu.getDecimalAccumulator().back().getValue();
}

bool Decimal::operator!=(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.nottDecimal();
    return cpu.getDecimalAccumulator().back().getValue();
}

bool Decimal::operator>(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.greaterDecimal();
    return cpu.getDecimalAccumulator().back().getValue();
}

bool Decimal::operator<(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.lessDecimal();
    return cpu.getDecimalAccumulator().back().getValue();
}

bool Decimal::operator>=(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.greaterOrDecimal();
    return cpu.getDecimalAccumulator().back().getValue();
}

bool Decimal::operator<=(Decimal &other) const
{
    cpu.loadDecimal(location);
    cpu.loadDecimal(other.location);
    cpu.lessOrDecimal();
    return cpu.getDecimalAccumulator().back().getValue();
}

BOOL BOOL::operator==(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.compBool();
    return cpu.getBoolAccumulator().back();
}

bool BOOL::operator&&(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.anddBool();
    return cpu.getBoolAccumulator().back().getValue();
}

bool BOOL::operator||(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.orrBool();
    return cpu.getBoolAccumulator().back().getValue();
}

bool BOOL::operator!=(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.nottBool();
    return cpu.getBoolAccumulator().back().getValue();
}

bool BOOL::operator>(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.greaterBool();
    return cpu.getBoolAccumulator().back().getValue();
}

bool BOOL::operator<(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.lessBool();
    return cpu.getBoolAccumulator().back().getValue();
}

bool BOOL::operator>=(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.greaterOrBool();
    return cpu.getBoolAccumulator().back().getValue();
}

bool BOOL::operator<=(BOOL &other) const
{
    cpu.loadBool(location);
    cpu.loadBool(other.location);
    cpu.lessOrBool();
    return cpu.getBoolAccumulator().back().getValue();
}

namespace yoi
{
    using std::cout;
    using std::string;
    using std::endl;
    using std::vector;
    using std::cin;

    void printer(const std::string b)
    {
        cout << b << endl;
    }

    void print(const Whole &numbr)
    {
        cout << numbr << endl;
    }

    void enter(Whole &numbr)
    {
        cin >> numbr;
    }

    void print(const Decimal &dec)
    {
        cout << dec << endl;
    }

    void enter(Decimal &dec)
    {
        cin >> dec;
    }

    void print(const BOOL &bol)
    {
        cout << bol << endl;
    }

    void enter(BOOL &bol)
    {
        cin >> bol;
    }
}









