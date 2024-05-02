class App{
private:
    Json m_json;
public:
     std::vector<std::vector<Input>> m_read_result();
     Table m_read_table();
     Colors m_read_colors();
     Main m_read_main();
     Dialog m_read_dialog();
     Help m_read_help();
     AddSearchEdit m_read_add_search_edit(std::string name);
     Confirm m_read_confirm();
     Delete m_read_delete();
     void m_write_result(std::vector<std::vector<Input>> result);
     Json m_read_setting();
};

Table App::m_read_table() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["tables"].template get<Table>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Colors App::m_read_colors() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["color"].template get<Colors>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Main App::m_read_main() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        Main m_main = JsonFile["eng"]["main"].template get<Main>();
        if (m_main.m_input_key_add == m_main.m_input_key_search) {
            m_main.m_input_key_add = m_main.m_input_key_add + "1";
            m_main.m_input_key_search = m_main.m_input_key_search + "2";
        }
        return m_main;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Dialog App::m_read_dialog() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["dialog"].template get<Dialog>();
        //return add;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Help App::m_read_help() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["help"].template get<Help>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
AddSearchEdit App::m_read_add_search_edit(std::string name) {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);

        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);

        return  JsonFile["eng"][name].template get<AddSearchEdit>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Confirm App::m_read_confirm() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        Confirm confirm = JsonFile["eng"]["confirm"].template get<Confirm>();
        if (confirm.m_input_key_edit == confirm.m_input_key_delete) {
            confirm.m_input_key_edit = confirm.m_input_key_edit + "1";
            confirm.m_input_key_delete = confirm.m_input_key_delete + "2";
        }
        return confirm;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Delete App::m_read_delete() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["delete"].template get<Delete>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
std::vector<std::vector<Input>> App::m_read_result() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        nlohmann::json myResult = JsonFile["result"];
        std::vector<std::vector<Input>> vec;
        for (int i = 0; i < myResult.size(); i++) {
            vec.push_back(std::vector<Input>());
            for (int ii = 0; ii < myResult.at(i).size(); ii++) {
                Input inp = myResult.at(i).at(ii).template get<Input>();
                vec[i].push_back(inp);
            }
        }

        return vec;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
void App::m_write_result(std::vector<std::vector<Input>> result) {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile = nlohmann::json::parse(MyReadFile);
        if (m_json.m_application != "" && m_json.m_name != "") 
            JsonFile.at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name)["result"] = result;
        else
            JsonFile.at("data").at(m_json.m_index)["result"] = result;
        std::ofstream myfile;
        myfile.open(TEXT_FIE_PATH);
        myfile << JsonFile;
        myfile.close();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Json App::m_read_setting(){
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile = nlohmann::json::parse(MyReadFile);
        this->m_json = JsonFile.template get<Json>();
        return this->m_json;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
