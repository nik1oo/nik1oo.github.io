#include "generator/generator.h"

Generator* generator;

int main(int argc, char* argv[]) {
	generator = calloc(1, sizeof(Generator));
	begin(generator);

	String page_name = STRING("index");
	page_block(page_name) {
		html_element_block(STRING("en")) {
			head_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
				meta_charset_element();
				title_element(STRING("Nikola Stefanov"));
				script_element(STRING("script.js"), false);
				link_stylesheet_element(STRING("style.css"));
			}
			body_element_block((Global_Attributes){ .class = STRING("my-body") }) {
				header_element_block((Global_Attributes){ .class = STRING("my-header") }) {
					h1_element(STRING("Nikola Stefanov"));
					nav_element_block((Global_Attributes){ .class = STRING("my-nav") }) {
					}
				}
				footer_element_block(DEFAULT_GLOBAL_ATTRIBUTES) { }
			}
		}
	}

	HTML_File html_file = html_file_from_typst(STRING("source/content/game-soap-glider.typ"));
	html_file = html_file_search_element_depth_first(html_file, HTML_ELEMENT_BODY);
	html_file_to_string(html_file);
	return 0; }
