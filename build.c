#include "generator/generator.h"

extern Generator* generator;



const String COLOR_FOREGROUND_STRING = COMPTIME_STRING("#2b2b2b");
const String COLOR_BACKGROUND_STRING = COMPTIME_STRING("#F7F5F2");



void pgprint_head() {
	pgprint_head_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
		pgprint_meta_charset_element();
		pgprint_title_element(STRING("Nikola Stefanov"), DEFAULT_GLOBAL_ATTRIBUTES);
		pgprint_script_element(STRING("script.js"), false);
		pgprint_link_stylesheet_element(STRING("/style.css")); } }

void pgprint_header() {
	// pgprint_div_element_block((Global_Attributes){ .class = STRING("overlay") });
	pgprint_header_element_block((Global_Attributes){ .class = STRING("my-header") }) {
		pgprint_h1_element(STRING("Nikola Stefanov"), DEFAULT_GLOBAL_ATTRIBUTES);
		pgprint_ul_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
			pgprint_li_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
				pgprint_a_element_block(STRING("/index.html"), DEFAULT_GLOBAL_ATTRIBUTES) { pgprint_string(STRING("Home")); } }
			pgprint_li_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
				pgprint_a_element_block(STRING("/games.html"), DEFAULT_GLOBAL_ATTRIBUTES) { pgprint_string(STRING("Games")); } }
			pgprint_li_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
				pgprint_a_element_block(STRING("/other.html"), DEFAULT_GLOBAL_ATTRIBUTES) { pgprint_string(STRING("Other")); } }
			// pgprint_li_element_block(DEFAULT_GLOBAL_ATTRIBUTES) {
			// 	pgprint_a_element_block(STRING("blog.html"), DEFAULT_GLOBAL_ATTRIBUTES) { pgprint_string(STRING("Blog")); } }
		}
		// pgprint_hr_element();
		pgprint_nav_element_block((Global_Attributes){ .class = STRING("my-nav") }) {
		} } }

int main(int argc, char* argv[]) {
	generator = calloc(1, sizeof(Generator));
	begin(generator);

	//////////////////////////
	// INTRO PAGE
	//
	HTML_File intro_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/intro.typ")), HTML_ELEMENT_BODY);
	const String index_page_name = COMPTIME_STRING("docs\\index");
	pgprint_page_block(index_page_name) {
		pgprint_html_element_block(STRING("en")) {
			pgprint_head();
			pgprint_body_element_block(GLOBAL_ATTRIBUTES(.class = STRING("my-body"))) {
				pgprint_header();
				pgprint_string(html_file_to_string(intro_file));
				pgprint_footer_element_block(DEFAULT_GLOBAL_ATTRIBUTES) { }
			}
		}
	}

	//////////////////////////
	// GAMES PAGE
	//
	HTML_File game_soap_glider_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/game-soap-glider.typ")), HTML_ELEMENT_BODY);
	HTML_File game_the_blue_break_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/game-blue-break.typ")), HTML_ELEMENT_BODY);
	HTML_File game_bribe_artist_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/game-bribe-artist.typ")), HTML_ELEMENT_BODY);
	HTML_File game_wanda_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/game-wanda.typ")), HTML_ELEMENT_BODY);
	HTML_File game_bogwalker_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/game-bogwalker.typ")), HTML_ELEMENT_BODY);
	HTML_File game_royal_dispute_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/game-royal-dispute.typ")), HTML_ELEMENT_BODY);
	const String games_page_name = COMPTIME_STRING("docs\\games");
	pgprint_page_block(games_page_name) {
		pgprint_html_element_block(STRING("en")) {
			pgprint_head();
			pgprint_body_element_block((Global_Attributes){ .class = STRING("my-body") }) {
				pgprint_header();
				pgprint_h2_element(STRING("Ultimate Skeleton"), GLOBAL_ATTRIBUTES(.id = STRING("ultimate-skeleton")));
				pgprint_string(html_file_to_string(game_soap_glider_file));
				pgprint_hr_element();
				pgprint_h2_element(STRING("The Blue Break"), GLOBAL_ATTRIBUTES(.id = STRING("the-blue-break")));
				pgprint_string(html_file_to_string(game_the_blue_break_file));
				pgprint_hr_element();
				pgprint_h2_element(STRING("Royal Dispute"), GLOBAL_ATTRIBUTES(.id = STRING("royal-dispute")));
				pgprint_string(html_file_to_string(game_royal_dispute_file));
				pgprint_hr_element();
				pgprint_h2_element(STRING("Bribe Artist"), GLOBAL_ATTRIBUTES(.id = STRING("bribe-artist")));
				pgprint_string(html_file_to_string(game_bribe_artist_file));
				pgprint_hr_element();
				pgprint_h2_element(STRING("Wanda"), GLOBAL_ATTRIBUTES(.id = STRING("wanda")));
				pgprint_string(html_file_to_string(game_wanda_file));
				pgprint_hr_element();
				pgprint_h2_element(STRING("Bogwalker"), GLOBAL_ATTRIBUTES(.id = STRING("bogwalker")));
				pgprint_string(html_file_to_string(game_bogwalker_file));
			}
		}
	}

	//////////////////////////
	// OTHER PAGE
	//
	HTML_File other_gasbol_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/other-gasbol.typ")), HTML_ELEMENT_BODY);
	const String other_page_name = COMPTIME_STRING("docs\\other");
	pgprint_page_block(other_page_name) {
		pgprint_html_element_block(STRING("en")) {
			pgprint_head();
			pgprint_body_element_block((Global_Attributes){ .class = STRING("my-body") }) {
				pgprint_header();
				pgprint_string(html_file_to_string(other_gasbol_file));
			}
		}
	}

	//////////////////////////
	// BLOG PAGE
	//
	const String blog_page_name = COMPTIME_STRING("docs\\blog");
	pgprint_page_block(blog_page_name) {
		pgprint_html_element_block(STRING("en")) {
			pgprint_head();
			pgprint_body_element_block((Global_Attributes){ .class = STRING("my-body") }) {
				pgprint_header();
			}
		}
	}

	//////////////////////////
	// ULTIMATE SKELETON PAGE
	//
	HTML_File ultimate_skeleton_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/ultimate-skeleton.typ")), HTML_ELEMENT_BODY);
	const String ultimate_skeleton_page_name = COMPTIME_STRING("docs\\ultimate-skeleton");
	pgprint_page_block(ultimate_skeleton_page_name) {
		pgprint_html_element_block(STRING("en")) {
			pgprint_head();
			pgprint_body_element_block((Global_Attributes){ .class = STRING("my-body") }) {
				pgprint_header();
				pgprint_string(html_file_to_string(ultimate_skeleton_file));
				pgprint_footer_element_block(DEFAULT_GLOBAL_ATTRIBUTES) { }
			}
		}
	}

	//////////////////////////
	// THE BLUE BREAK PAGE
	//
	HTML_File the_blue_break_file = html_file_search_element_depth_first(html_file_from_typst(STRING("source/content/the-blue-break.typ")), HTML_ELEMENT_BODY);
	const String the_blue_break_page_name = COMPTIME_STRING("docs\\the-blue-break");
	pgprint_page_block(the_blue_break_page_name) {
		pgprint_html_element_block(STRING("en")) {
			pgprint_head();
			pgprint_body_element_block((Global_Attributes){ .class = STRING("my-body") }) {
				pgprint_header();
				pgprint_string(html_file_to_string(the_blue_break_file));
				pgprint_footer_element_block(DEFAULT_GLOBAL_ATTRIBUTES) { }
			}
		}
	}

	//////////////////////////
	// STYLE
	//
	const String style_name = COMPTIME_STRING("docs\\style");
	pgprint_style_block(style_name) {
		pgprint_charset_atrule(STRING("utf-8"));
		pgprint_font_face_atrule(STRING("Radley Regular"), STRING("Radley-Regular.ttf"));
		pgprint_font_face_atrule(STRING("Goudy Bookletter 1911 Regular"), STRING("GoudyBookletter1911-Regular.ttf"));
		pgprint_font_face_atrule(STRING("Sorts Mill Goudy Regular"), STRING("SortsMillGoudy-Regular.ttf"));
		pgprint_font_face_atrule(STRING("Crimson Text Regular"), STRING("CrimsonText-Regular.ttf"));
		pgprint_font_face_atrule(STRING("EB Garamond Regular"), STRING("EBGaramond-Medium.ttf"));
		pgprint_font_face_atrule(STRING("Trocchi Regular"), STRING("Trocchi-Regular.ttf"));
		pgprint_generic_rule_block(STRING("html")) {
			pgprint_generic_declaration(STRING("font-family"), STRING("\"Trocchi Regular\""));
			pgprint_generic_declaration(STRING("font-size"), STRING("1.8vh"));
			pgprint_generic_declaration(STRING("color"), COLOR_FOREGROUND_STRING);
			pgprint_generic_declaration(STRING("background-color"), COLOR_BACKGROUND_STRING);
			pgprint_generic_declaration(STRING("text-rendering"), STRING("optimizeLegibility"));
			pgprint_generic_declaration(STRING("word-spacing"), STRING("0.1em"));
			pgprint_generic_declaration(STRING("font-feature-settings"), STRING("'kern', 'liga', 'cpsp' on"));
		}
		pgprint_generic_rule_block(STRING("body")) {
			pgprint_generic_declaration(STRING("width"), STRING("auto"));
			pgprint_generic_declaration(STRING("margin-inline"), STRING("calc(max((100vw - 800px) / 2, 5vw))"));
			pgprint_generic_declaration(STRING("margin-bottom"), STRING("50vh"));
		}
		pgprint_generic_rule_block(STRING("h1")) {
			pgprint_generic_declaration(STRING("font-size"), STRING("4.4vh"));
			pgprint_generic_declaration(STRING("font-family"), STRING("\"Trocchi Regular\""));
		}
		pgprint_generic_rule_block(STRING("h2")) {
			pgprint_generic_declaration(STRING("font-size"), STRING("2.8vh"));
		}
		pgprint_generic_rule_block(STRING("hr")) {
			pgprint_generic_declaration(STRING("color"), COLOR_FOREGROUND_STRING);
			pgprint_generic_declaration(STRING("border-top"), STRING("2px solid #2b2b2b"));
			pgprint_generic_declaration(STRING("border-bottom"), STRING("3px solid #d6d5eb"));
		}
		pgprint_generic_rule_block(STRING("img, video")) {
			pgprint_generic_declaration(STRING("border"), STRING("2px solid #2b2b2b"));
			pgprint_generic_declaration(STRING("box-shadow"), STRING("0px 3px #d6d5eb"));
			pgprint_generic_declaration(STRING("width"), STRING("100%"));
			pgprint_generic_declaration(STRING("height"), STRING("auto"));
			pgprint_generic_declaration(STRING("display"), STRING("block"));
			pgprint_generic_declaration(STRING("position"), STRING("relative"));
			pgprint_generic_declaration(STRING("z-index"), STRING("2000"));
		}
		pgprint_generic_rule_block(STRING(".selfie")) {
			pgprint_generic_declaration(STRING("border"), STRING("2px solid #2b2b2b"));
			pgprint_generic_declaration(STRING("width"), STRING("30%"));
			pgprint_generic_declaration(STRING("border-radius"), STRING("50%"));
		}
		pgprint_generic_rule_block(STRING("a:link, a:visited")) {
			pgprint_generic_declaration(STRING("color"), STRING("#585cdf"));
		}
		pgprint_generic_rule_block(STRING("a:hover")) {
			pgprint_generic_declaration(STRING("color"), STRING("#4907FF"));
		}
		pgprint_generic_rule_block(STRING("ul")) {
			pgprint_generic_declaration(STRING("list-style-type"), STRING("none"));
			pgprint_generic_declaration(STRING("padding"), STRING("0"));
			pgprint_generic_declaration(STRING("overflow"), STRING("hidden"));
			pgprint_generic_declaration(STRING("margin"), STRING("0"));
			pgprint_generic_declaration(STRING("margin-bottom"), STRING("1em"));
		}
		pgprint_generic_rule_block(STRING("li")) {
			pgprint_generic_declaration(STRING("float"), STRING("left"));
			pgprint_generic_declaration(STRING("padding-right"), STRING("10pt"));
		}
		pgprint_generic_rule_block(STRING(".overlay")) {
			pgprint_generic_declaration(STRING("background-image"), STRING("url('overlay.png')"));
			pgprint_generic_declaration(STRING("position"), STRING("fixed"));
			pgprint_generic_declaration(STRING("inset"), STRING("0"));
			pgprint_generic_declaration(STRING("pointer-events"), STRING("none"));
			pgprint_generic_declaration(STRING("z-index"), STRING("1000"));
			pgprint_generic_declaration(STRING("background-repeat"), STRING("repeat"));
			pgprint_generic_declaration(STRING("background-size"), STRING("auto"));
			pgprint_generic_declaration(STRING("background-position"), STRING("0 0"));
			pgprint_generic_declaration(STRING("mix-blend-mode"), STRING("overlay"));
			pgprint_generic_declaration(STRING("opacity"), STRING("0.5"));
		}
	}

	return 0; }
