import re
import sys

src, dst = sys.argv[1], sys.argv[2]
text = open(src).read()

# %hook(Class)  ->  SMT_BEGIN(Class)
text = re.sub(r'^[ \t]*%hook\((\w+)\)', r'SMT_BEGIN(\1)', text, flags=re.M)

out = []
cur = None
for line in text.split('\n'):
    m = re.match(r'^[ \t]*SMT_BEGIN\((\w+)\)', line)
    if m:
        cur = m.group(1)
    if re.match(r'^[ \t]*%end\b', line):
        line = re.sub(r'^([ \t]*)%end\b.*$', r'\1SMT_END(%s)' % cur, line)
    out.append(line)

text = '\n'.join(out).replace('%orig', 'SMT_ORIG')
open(dst, 'w').write(text)
