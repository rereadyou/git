#include "submodule.h"
	GIT_COLOR_NORMAL,	/* FUNCINFO */
	if (!strcasecmp(var+ofs, "func"))
		return DIFF_FUNCINFO;
	return -1;
		if (slot < 0)
			return 0;
	struct strbuf *header;
	if (len || !nofirst) {
		fputs(set, file);
		if (!nofirst)
			fputc(first, file);
		fwrite(line, len, 1, file);
		fputs(reset, file);
	}
static void emit_hunk_header(struct emit_callback *ecbdata,
			     const char *line, int len)
{
	const char *plain = diff_get_color(ecbdata->color_diff, DIFF_PLAIN);
	const char *frag = diff_get_color(ecbdata->color_diff, DIFF_FRAGINFO);
	const char *func = diff_get_color(ecbdata->color_diff, DIFF_FUNCINFO);
	const char *reset = diff_get_color(ecbdata->color_diff, DIFF_RESET);
	static const char atat[2] = { '@', '@' };
	const char *cp, *ep;

	/*
	 * As a hunk header must begin with "@@ -<old>, +<new> @@",
	 * it always is at least 10 bytes long.
	 */
	if (len < 10 ||
	    memcmp(line, atat, 2) ||
	    !(ep = memmem(line + 2, len - 2, atat, 2))) {
		emit_line(ecbdata->file, plain, reset, line, len);
		return;
	}
	ep += 2; /* skip over @@ */

	/* The hunk header in fraginfo color */
	emit_line(ecbdata->file, frag, reset, line, ep - line);

	/* blank before the func header */
	for (cp = ep; ep - line < len; ep++)
		if (*ep != ' ' && *ep != '\t')
			break;
	if (ep != cp)
		emit_line(ecbdata->file, plain, reset, cp, ep - cp);

	if (ep < line + len)
		emit_line(ecbdata->file, func, reset, ep, line + len - ep);
}

	if (ecbdata->header) {
		fprintf(ecbdata->file, "%s", ecbdata->header->buf);
		strbuf_reset(ecbdata->header);
		ecbdata->header = NULL;
	}
		emit_hunk_header(ecbdata, line, len);
static void show_shortstats(struct diffstat_t *data, struct diff_options *options)
	struct strbuf header = STRBUF_INIT;

	if (DIFF_OPT_TST(o, SUBMODULE_LOG) &&
			(!one->mode || S_ISGITLINK(one->mode)) &&
			(!two->mode || S_ISGITLINK(two->mode))) {
		const char *del = diff_get_color_opt(o, DIFF_FILE_OLD);
		const char *add = diff_get_color_opt(o, DIFF_FILE_NEW);
		show_submodule_summary(o->file, one ? one->path : two->path,
				one->sha1, two->sha1,
				del, add, reset);
		return;
	}
	strbuf_addf(&header, "%sdiff --git %s %s%s\n", set, a_one, b_two, reset);
		strbuf_addf(&header, "%snew file mode %06o%s\n", set, two->mode, reset);
			strbuf_addf(&header, "%s%s%s\n", set, xfrm_msg, reset);
		strbuf_addf(&header, "%sdeleted file mode %06o%s\n", set, one->mode, reset);
			strbuf_addf(&header, "%s%s%s\n", set, xfrm_msg, reset);
			strbuf_addf(&header, "%sold mode %06o%s\n", set, one->mode, reset);
			strbuf_addf(&header, "%snew mode %06o%s\n", set, two->mode, reset);
			strbuf_addf(&header, "%s%s%s\n", set, xfrm_msg, reset);

			fprintf(o->file, "%s", header.buf);
			strbuf_reset(&header);
		fprintf(o->file, "%s", header.buf);
		strbuf_reset(&header);
		if (!DIFF_XDL_TST(o, WHITESPACE_FLAGS)) {
			fprintf(o->file, "%s", header.buf);
			strbuf_reset(&header);
		}

		ecbdata.header = header.len ? &header : NULL;
	strbuf_release(&header);
	/*
	 * Most of the time we can say "there are changes"
	 * only by checking if there are changed paths, but
	 * --ignore-whitespace* options force us to look
	 * inside contents.
	 */

	if (DIFF_XDL_TST(options, IGNORE_WHITESPACE) ||
	    DIFF_XDL_TST(options, IGNORE_WHITESPACE_CHANGE) ||
	    DIFF_XDL_TST(options, IGNORE_WHITESPACE_AT_EOL))
		DIFF_OPT_SET(options, DIFF_FROM_CONTENTS);
	else
		DIFF_OPT_CLR(options, DIFF_FROM_CONTENTS);

	if (DIFF_OPT_TST(options, QUICK)) {
		DIFF_OPT_SET(options, QUICK);
	else if (!strcmp(arg, "--submodule"))
		DIFF_OPT_SET(options, SUBMODULE_LOG);
	else if (!prefixcmp(arg, "--submodule=")) {
		if (!strcmp(arg + 12, "log"))
			DIFF_OPT_SET(options, SUBMODULE_LOG);
	}

	/*
	 * Report the content-level differences with HAS_CHANGES;
	 * diff_addremove/diff_change does not set the bit when
	 * DIFF_FROM_CONTENTS is in effect (e.g. with -w).
	 */
	if (DIFF_OPT_TST(options, DIFF_FROM_CONTENTS)) {
		if (options->found_changes)
			DIFF_OPT_SET(options, HAS_CHANGES);
		else
			DIFF_OPT_CLR(options, HAS_CHANGES);
	}
	if (diff_queued_diff.nr && !DIFF_OPT_TST(options, DIFF_FROM_CONTENTS))
	if (!DIFF_OPT_TST(options, DIFF_FROM_CONTENTS))
		DIFF_OPT_SET(options, HAS_CHANGES);
	if (!DIFF_OPT_TST(options, DIFF_FROM_CONTENTS))
		DIFF_OPT_SET(options, HAS_CHANGES);