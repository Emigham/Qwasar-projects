function my_levenshtein(string1, string2) {
    count = 0;
    for (index = 0;index < string1.length && index < string2.length;index++) {
        if (string1.length == string2.length) {
            if (!string1[index].includes(string2[index])) {
                count++;
            }
        }
        else {
            return -1;
        }
    }
    return count;

}