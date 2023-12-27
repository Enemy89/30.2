#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Header headers = {{"Accept", "text/html"}};

    cpr::Response r = cpr::Get(cpr::Url{"http://httpbin.org/html"}, headers);

    if (r.status_code == 200) {
        size_t h1_start = r.text.find("<h1>");
        size_t h1_end = r.text.find("</h1>");

        if (h1_start != std::string::npos && h1_end != std::string::npos && h1_end > h1_start) {
            std::string article_header = r.text.substr(h1_start + 4, h1_end - h1_start - 4);
            std::cout << "Article Header: " << article_header << std::endl;
        } else {
            std::cout << "Article Header not found in response." << std::endl;
        }
    } else {
        std::cout << "Error: " << r.status_code << std::endl;
    }
}
