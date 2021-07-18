#include <gtk/gtk.h>
#include <libgen.h> // dirname()
#include <stdlib.h>
#include <stdio.h>
// #include <time.h>

GtkBuilder* builderfromfile(char* path) {
	char ui_file_path[256];
	if (readlink("/proc/self/exe", ui_file_path, sizeof(ui_file_path)) == -1) {
		printf("Couldn't get location of binary\n");
		exit(1);
	}

	dirname(ui_file_path);
	strcat(ui_file_path, "/");
	strcat(ui_file_path, path);
	return gtk_builder_new_from_file(ui_file_path);
}

char* exec(char* fileloc) {
	FILE* file;
	char path[1035];
	char* output = "";

	file = popen(fileloc, "r");
	if (file == NULL) {
		printf("Failed to exec\n");
		exit(1);
	}

	while (fgets(path, sizeof(path), file) != NULL) {
		strcat(output, path);
	}

	return output;
}

// Returns 1 if it isn't running and 0 if it is
int bluetoothRunning() {
	char* btstatusstr = exec("/usr/local/bin/Xe-Bluetooth-status.sh");
	int btstatus = atoi(btstatusstr);
	return btstatus;
}
