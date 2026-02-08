#include "generator/generator.h"

Generator* generator;

int main(int argc, char* argv[]) {
	generator = calloc(1, sizeof(Generator));
	begin(generator);

	HTML_File intro_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/intro.typ")), HTML_ELEMENT_BODY);
	// HTML_File soap_glider_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/game-soap-glider.typ")), HTML_ELEMENT_BODY);
	String page_name = STRING("docs\\index");
	pgprint_page_block(page_name) {
		pgprint_html_element_block(STRING("en")) {
			pgprint_head_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
				pgprint_meta_charset_element();
				pgprint_title_element(STRING("Nikola Stefanov"));
				pgprint_script_element(STRING("script.js"), false);
				pgprint_link_stylesheet_element(STRING("style.css"));
			}
			pgprint_body_element_block((Global_Attributes){ .class = STRING("my-body") }) {
				pgprint_header_element_block((Global_Attributes){ .class = STRING("my-header") }) {
					pgprint_h1_element(STRING("Nikola Stefanov"));
					pgprint_nav_element_block((Global_Attributes){ .class = STRING("my-nav") }) {
					}
				}
				pgprint_string(html_file_to_string(intro_file));
				// pgprint_string(html_file_to_string(soap_glider_file));
				pgprint_footer_element_block(DEFAULT_GLOBAL_ATTRIBUTES) { }
			}
		}
	}

	return 0; }
