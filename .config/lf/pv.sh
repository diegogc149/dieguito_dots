#!/bin/sh

file="$1"
width="$2"
height="$3"
x="$4"
y="$5"
printf '\033_Ga=d\033\\' >/dev/tty

mime_type=$(file -Lb --mime-type -- "$file")

case "$mime_type" in
image/*)
  printf '\033_Ga=d\033\\' >/dev/tty
  exec kitty +kitten icat --transfer-mode=memory --clear --stdin=no \
    --place="${width}x${height}@${x}x${y}" -- "$file" \
    >/dev/tty </dev/tty 2>/dev/null
  ;;

video/* | audio/*)
  if command -v mediainfo >/dev/null 2>&1; then
    mediainfo -- "$file"
  else
    echo "Multimedia: $file"
  fi
  ;;

application/pdf)
  if command -v pdftotext >/dev/null 2>&1; then
    pdftotext -- "$file" - | head -n 100
  else
    echo "[PDF File]: $file"
  fi
  ;;

application/zip | application/x-tar | application/x-7z-compressed | application/x-compressed-tar | application/x-bzip2 | application/x-xz)
  tar -tvf -- "$file" 2>/dev/null || unzip -l -- "$file" 2>/dev/null || 7z l -- "$file" 2>/dev/null
  ;;

inode/directory)
  ls -la --color=always -- "$file"
  ;;

text/* | application/json | application/javascript | application/x-sh)
  if command -v bat >/dev/null 2>&1; then
    bat --color=always --style=plain --pager=never -- "$file"
  else
    cat -- "$file"
  fi
  ;;

*)
  if head -c 1024 -- "$file" | grep -qP '^[\x09\x0A\x0D\x20-\x7E]*$'; then
    if command -v bat >/dev/null 2>&1; then
      bat --color=always --style=plain --pager=never -- "$file"
    else
      cat -- "$file"
    fi
  else
    echo "Binary file"
  fi
  ;;
esac
