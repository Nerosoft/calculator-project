class Input{
public:
    std::string m_var1 = "";
    std::string m_operator = "";
    std::string m_result = "";
    std::string m_index = "";

    Input() = default;
    Input(std::string var1, std::string operator1, std::string result)
        : m_var1(var1), m_operator(operator1), m_result(result)
    {}
    Input(std::string var1, std::string operator1, std::string result, std::string index)
        : m_var1(var1), m_operator(operator1), m_result(result), m_index(index)
    {}
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Input, m_var1, m_operator, m_result)
};
