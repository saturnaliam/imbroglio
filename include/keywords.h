typedef struct keyword {
    /**
     * \brief The value the keyword is converted to upon processing
     *
     */
    char value;

    /**
     * \brief Identifier used in the .ism file
     *
     */
    char* identifier;
} keyword;

/**
 * \brief Keywords used in the language
 *
 */
const keyword KEYWORDS[12] = {
    {'a', "ADD"}, {'s', "SUB"},
    {'A', "ADT"}, {'S', "SBT"},
    {'r', "MVR"}, {'l', "MVL"},
    {'R', "MRT"}, {'L', "MLT"},
    {'[', "SLP"}, {']', "ELP"},
    {'p', "PUT"}, {'g', "GET"}
};

