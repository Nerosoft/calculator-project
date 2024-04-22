#pragma once
class AddSearchEdit {
public:
    std::string m_print_statement_confirm;
    std::string m_print_error_statement_confirm;
    std::string m_print_successfully_statement_message_confirm;

    std::string m_print_number;
    std::string m_print_error_number;
    std::string m_print_operator;
    std::string m_print_error_operator;

    std::string m_input_clear;
    std::string m_print_clear;

    std::string m_input_y;
    std::string m_input_n;
    std::string m_input_result_table;
    AddSearchEdit() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(AddSearchEdit,
        m_print_statement_confirm,
        m_print_error_statement_confirm,
        m_print_successfully_statement_message_confirm,

        m_print_number,
        m_print_error_number,
        m_print_operator,
        m_print_error_operator,

        m_input_clear,
        m_print_clear,

        m_input_y,
        m_input_n,
        m_input_result_table
    )
};
