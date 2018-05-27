#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

GtkWidget *window;
GtkWidget *word_label, *value_label, *path_label;
GtkWidget *word_entry, *value_entry, *path_entry;
GtkWidget *ok_button, *ok_button2;
GtkWidget *hbox1, *hbox2, *hbox3;
GtkWidget *vbox;


// void message(gpointer str) {
// 	GtkWidget *dialog;
// 	dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, (gchar*)str);
// 	gtk_dialog_run(GTK_DIALOG(dialog));
// 	gtk_widget_destroy(dialog);
// }

///home/vimi/Desktop/vimiFloder
const char *result = "result.txt";

void closeApp(GtkWidget *window, gpointer data) {
	gtk_main_quit();
}

int calc(const char * str) {
	int ans = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') ans += str[i] - 'A' + 1;
	}
	return ans;
}

void button_clicked(GtkWidget *window, gpointer data) {
	const char * str = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
	int ans = calc(str);
	char put[10];
	sprintf(put, "%d", ans);
	gtk_entry_set_text(GTK_ENTRY(value_entry), (gchar*)put);
}

void button_clicked2(GtkWidget *window, gpointer data) {
	const char * str = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
	FILE *fp = fopen(str, "r");
	if (fp == NULL) {
		const char *put = "file not exist";
		gtk_entry_set_text(GTK_ENTRY(path_entry), (gchar*)put);
	} else {
		int be = -1;
		for (int i = strlen(str) - 1; i >= 0; --i) {
			if (str[i] == '/') {
				be = i;
				break;
			}
		}
		if (be == -1) return;
		char write[256];
		int to = 0;
		for (int i = 0; i <= be; ++i) write[to++] = str[i];
		for (int i = 0; i < strlen(result); ++i) write[to++] = result[i];
		write[to] = '\0';

		printf("%s\n", write);
		FILE *fpw = NULL;
		char line[256];
		while (fscanf(fp, "%s", line) > 0) {
			if (fpw == NULL) {
				fpw = fopen(write, "w");
			}
			int ans = calc(line);
			fprintf(fpw, "%d\n", ans);
			printf("%s\n", line);
		}
		fclose(fp);
		if (fpw != NULL) {
			fclose(fpw);
			gtk_entry_set_text(GTK_ENTRY(path_entry), (gchar*)("calc finish"));
		} else {
			gtk_entry_set_text(GTK_ENTRY(path_entry), (gchar*)("it is a floder?"));
		}
	}
}

int main(int argc, char *argv[]) {
	// message("fuckl");
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "vimi_calc");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

	g_signal_connect(GTK_OBJECT(window), "destory", GTK_SIGNAL_FUNC(closeApp), NULL);

	word_label = gtk_label_new("请输入单词:");
	value_label = gtk_label_new("该单词值:");
	path_label = gtk_label_new("输入文件路径:");

	word_entry = gtk_entry_new();
	value_entry = gtk_entry_new();
	path_entry = gtk_entry_new();

	gtk_entry_set_visibility(GTK_ENTRY(value_entry), TRUE); // default is true

	ok_button = gtk_button_new_with_label("计算");
	ok_button2 = gtk_button_new_with_label("计算");

	g_signal_connect(GTK_OBJECT(ok_button), "clicked", GTK_SIGNAL_FUNC(button_clicked), word_entry);
	g_signal_connect(GTK_OBJECT(ok_button2), "clicked", GTK_SIGNAL_FUNC(button_clicked2), path_entry);



	hbox1 = gtk_hbox_new(TRUE, 5);
	hbox2 = gtk_hbox_new(TRUE, 5);
	hbox3 = gtk_hbox_new(TRUE, 5);
	vbox = gtk_vbox_new(FALSE, 10);

	gtk_box_pack_start(GTK_BOX(hbox1), word_label, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox1), word_entry, TRUE, FALSE, 5);

	gtk_box_pack_start(GTK_BOX(hbox2), value_label, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox2), value_entry, TRUE, FALSE, 5);

	gtk_box_pack_start(GTK_BOX(hbox3), path_label, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox3), path_entry, TRUE, FALSE, 5);

	//===========================================================//
	gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), ok_button, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), hbox3, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), ok_button2, FALSE, FALSE, 5);
	//===========================================================//

	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}