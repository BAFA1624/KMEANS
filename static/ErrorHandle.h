#ifndef ERRORHANDLE_H
#define ERRORHANDLE_H

void 
err_exit(char* err_msg, int err_code) {
	fputs(err_msg, stderr);
	exit(err_code);
}

void
weak_err(char* err_msg) {
	fputs(err_msg, stderr);
}

#endif
