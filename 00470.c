int rand7();

// has a non-0 chance of running forever
int rand10() {
    // generates 2 digit base7 and converts into base10
    int random10 = rand7() * 7 + rand7() - 7;
    
    // drops 9 numbers to get 40
    return (random10 > 40) ? rand10() : 1 + random10 % 10;
}

// will always execute in 10 rand7's
int rand10in10() {
    int random10 = 0;
    for (int i = 0; i < 10; i++) {
        random10 += rand7();
    }
    return 1 + random10 % 10;
}