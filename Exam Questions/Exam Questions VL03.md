## Exam Questions VL03

##### Outline an algorithm to convert a string to an unsigned integer (no negative numbers).

```
unsigned int StringToInt(string s){
    unsigned int sum = 0;
    unsigned int count = 1;
    for(int i = s.length() - 1; i >= 0; i--){
        char c = s[i];
        switch(c){
            case '1': sum += count;
                    break;
            case '2': sum += 2 * count;
                    break;
            case '3': sum += 3 * count;
                    break;
            case '4': sum += 4 * count;
                    break;
            case '5': sum += 5 * count;
                    break;
            case '6': sum += 6 * count;
                    break;
            case '7': sum += 7 * count;
                    break;
            case '8': sum += 8 * count;
                    break;
            case '9': sum += 9 * count;
                    break;
            default: break;
        } 
        count*= 10;
    }
    return sum;
}
```

We start by looking at the string from behind. We look at the $10^0$ number and add accordingly. We do this until the end of the string and multiply count everytime by 10 so we have the right power of 10 when adding. If the string is 0 at some point we just skip, but still multiply by 10. In the end we return the sum of everything. 

--- 

##### Outline an algorithm to convert an unsigned integer to a string.

```
char returnChar(uint32_t c){
    switch(c){
        case 1: return '1';
                
        case 2: return '2';
                
        case 3: return '3';
                
        case 4: return '4';
                
        case 5: return '5';
                
        case 6: return '6';
                
        case 7: return '7';
                
        case 8: return '8';
                
        case 9: return '9';
                
        case 0: return '0'; 
        
        default: cerr << "this shouldn't happen\n";
                 return ' ';
    }
}

string intToString(uint32_t t){
    if(t == 0) return "0";
    string sum = "";
    uint32_t divider = 1000000000;
    while(t / divider == 0){
        t %= divider;
        divider /= 10;
    }
    
    sum += returnChar(t / divider);
    
    while(divider > 0){
        t %= divider;
        divider /= 10;
        sum += returnChar(t / divider);
    }
    
    return sum;
}
```

returnChar could also be inside of intToString, but it is way more easy to look at this way. First the maximum unsigned int (for 32bit) is 4294967295.
If we want to extract the '4' we have to divide by 10^9 which is exactly one tenth of the highest power of ten accepted by 32bit unsigned integer. In the algorithmen shown we extract every 0 before so don't add them to the number. After this we add the first number to the string and continue. We extract by always losing the highest power of ten by just simply doing t %= divider this way everything except the highest power of ten will stay inside ten. We then divide the divider by 10 so we can continue until we reach 10^0. After we completed the string we will return it.

---

##### Explain the characteristics of the character encodings ASCII, Extended ASCII, UTF-8, UTF-16 and UTF-32.

- ASCII only has about 128 characters and only 95 of them are printable
- Extended ACSII includes a full byte therefore 256 different characters and all of them are printable
- UTF-8 is a one to four byte. How much bytes are used is defined in the first byte. It is also backwards compatible to ASCII and has about 1.112.064 characters(according to Wikipedia)
- UTF-16 can variable-sized by using one or two words(where each word is 16 bit long) to encode
- UTF-32 always uses 4 Bytes and is the only one of those four that has a fixed size

---

##### What advice can you give to modify strings as quickly as possible?

I would recommend to use C-Style strings, because manipulation of them is faster and they have way less overhead compared to C++-Style strings.

---

##### Why are hardcoded regex expressions often much faster?

Using C++ or C functions always comes with an overhead and has edge cases in it which lengthen the runtime. If you just search for a specific pattern and you want to ignore every edge case you can hardcode them and they will be much faster.

---

##### Is run-length encoding a good compression method for strings?

Depending on the use, but nowerdays I would say it doesn't matter, because we have so much Memory and Storage it is unamagineable that using compressesion is needed. The only thing I can imagine is that you will have faster compare times on CPU, as you will have less Cache misses which will result in lower waiting time. (You can put more Data into your CPU-Cache)
