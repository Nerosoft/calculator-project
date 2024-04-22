#pragma once
class Help {
public:
    std::string m_input_help_add;
    std::string m_print_help_add;
    std::string m_input_help_search;
    std::string m_print_help_search;
    std::string m_input_help_edit;
    std::string m_print_help_edit;
    std::string m_input_help_main;
    std::string m_print_help_main;
    std::string m_input_help_confirm;
    std::string m_print_help_confirm;
    std::string m_input_help_delete;
    std::string m_print_help_delete;
    Help() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Help,
        m_input_help_add,
        m_print_help_add,
        m_input_help_search,
        m_print_help_search,
        m_input_help_edit,
        m_print_help_edit,
        m_input_help_main,
        m_print_help_main,
        m_input_help_confirm,
        m_print_help_confirm,
        m_input_help_delete,
        m_print_help_delete
    )
};
