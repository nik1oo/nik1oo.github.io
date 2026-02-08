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

	String typst_html = typst_file_to_html(STRING("source/content/game-soap-glider.typ"));
	return 0; }
