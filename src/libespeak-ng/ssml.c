/*
 * Copyright (C) 2005 to 2015 by Jonathan Duddington
 * email: jonsd@users.sourceforge.net
 * Copyright (C) 2015-2017 Reece H. Dunn
 * Copyright (C) 2018 Juho Hiltunen
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see: <http://www.gnu.org/licenses/>.
 */


#include "config.h"

#include <ctype.h>
#include <errno.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>


#include <espeak-ng/espeak_ng.h>
#include <espeak-ng/speak_lib.h>
#include <espeak-ng/encoding.h>
#include <ucd/ucd.h>

#include "ssml.h"
#include "dictionary.h"           // for strncpy0
#include "mnemonics.h"               // for LookupMnemName, MNEM_TAB, 
#include "readclause.h"           // for PARAM_STACK, param_stack, AddNameData
#include "soundicon.h"               // for LoadSoundFile2
#include "synthesize.h"           // for SPEED_FACTORS, speed
#include "translate.h"            // for CTRL_EMBEDDED, IsDigit09, utf8_out
#include "voice.h"                // for SelectVoice, SelectVoiceByName

static MNEM_TAB ssmltags[] = {
	{ "speak",     SSML_SPEAK },
	{ "voice",     SSML_VOICE },
	{ "prosody",   SSML_PROSODY },
	{ "say-as",    SSML_SAYAS },
	{ "mark",      SSML_MARK },
	{ "s",         SSML_SENTENCE },
	{ "p",         SSML_PARAGRAPH },
	{ "phoneme",   SSML_PHONEME },
	{ "sub",       SSML_SUB },
	{ "tts:style", SSML_STYLE },
	{ "audio",     SSML_AUDIO },
	{ "emphasis",  SSML_EMPHASIS },
	{ "break",     SSML_BREAK },
	{ "metadata",  SSML_IGNORE_TEXT },

	{ "br",     HTML_BREAK },
	{ "li",     HTML_BREAK },
	{ "dd",     HTML_BREAK },
	{ "img",    HTML_BREAK },
	{ "td",     HTML_BREAK },
	{ "h1",     SSML_PARAGRAPH },
	{ "h2",     SSML_PARAGRAPH },
	{ "h3",     SSML_PARAGRAPH },
	{ "h4",     SSML_PARAGRAPH },
	{ "hr",     SSML_PARAGRAPH },
	{ "script", SSML_IGNORE_TEXT },
	{ "style",  SSML_IGNORE_TEXT },
	{ "font",   HTML_NOSPACE },
	{ "b",      HTML_NOSPACE },
	{ "i",      HTML_NOSPACE },
	{ "strong", HTML_NOSPACE },
	{ "em",     HTML_NOSPACE },
	{ "code",   HTML_NOSPACE },

	{ NULL, 0 }
};

/********* Dummy Functions *********/

int ProcessSsmlTag(wchar_t *xml_buf, char *outbuf, int *outix, int n_outbuf, const char *xmlbase, bool *audio_text, char *current_voice_id, espeak_VOICE *base_voice, char *base_voice_variant_name, bool *ignore_text, bool *clear_skipping_text, int *sayas_mode, int *sayas_start, SSML_STACK *ssml_stack, int *n_ssml_stack, int *n_param_stack, int *speech_parameters)
{
	return 0;
}

int ParseSsmlReference(char *ref, int *c1, int *c2) {

	return -1; //Failure to Parse

}