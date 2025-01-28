---
Generator: Umba Brief Scanner
---

# _libs/encoding

- [ ] `[_libs/encoding/encoding.cpp:370]`
  А если продетектированная по BOM кодировка не соответствует заданной
  параметром?

- [ ] `[_libs/encoding/encoding.cpp:386]`
  разобраться, не будет ли precomposed всякие ударения соединять с символом?



# _libs/encoding/compact_enc_det

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:46]`
  as of 2007.10.09:
  
  Consider font=TT-BHxxx as user-defined => binary Demote GB18030 if no 8x3x pair
  Map byte2 ascii punct to 0x60, digits to 0x7e, gets them into hires Consider
  removing/ignoring bytes 01-1F to avoid crap pollution Possibly boost declared
  encoding in robust scan googlebot tiny files look for ranges of encodings
  consider tags just as > < within aligned block of 32 flag too few characters in
  postproc (Latin 6 problem) Remove slow scan beyond 16KB Consider removing
  kMostLikelyEncoding or cut it in half

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:343]`
  only allocate this if being used

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:1150]`
  change this to be per encoding, not permuted

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:1671]`
  This should all be folded into postproc-enc-detect.cc

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:1808]`
  This should all be folded into postproc-enc-detect.cc

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:1896]`
  This should all be folded into postproc-enc-detect.cc

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:2131]`
  make this more graceful

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:3978]`
  boost subset/superset also Boost(destatep, kRelatedEncoding[best_enc],
  kBestEncBoost);

- [ ] `[_libs/encoding/compact_enc_det/compact_enc_det.cc:4696]`
  also want to boost Shift-JIS here if byte1 is Ax..Dx TEMP printf(" 
  Rescore[%02x] %s +%d\n", high_hash, MyRankedEncName(rankedencoding),
  kGentlePairBoost);



# _libs/encoding/util

- [ ] `[_libs/encoding/util/basictypes.h:34]`
  (mbelshe) Remove these type guards.  These are temporary to avoid conflicts
  with npapi.h.

- [ ] `[_libs/encoding/util/basictypes.h:57]`
  (mbelshe) Remove these type guards.  These are temporary to avoid conflicts
  with npapi.h.



# _libs/encoding/util/encodings

- [ ] `[_libs/encoding/util/encodings/encodings.cc:315]`
  This list could be expanded.  Many other encodings are supersets of 7-bit
  Ascii.  In fact, Japanese JIS and Unicode are the only two encodings that I
  know for a fact should *not* be in this list.

- [ ] `[_libs/encoding/util/encodings/encodings.cc:374]`
  This list could maybe be expanded.  Other encodings may be 8-bit.

- [ ] `[_libs/encoding/util/encodings/encodings.cc:520]`
  Unify MimeEncodingName and EncodingName, or determine why such a unification is
  not possible.

- [ ] `[_libs/encoding/util/encodings/encodings.cc:525]`
  Should this be invalid_encoding_name()?

- [ ] `[_libs/encoding/util/encodings/encodings.cc:860]`
  Check if it is possible to remove the non-standard, non-netscape-use names. It
  is because this routine is used for encoding detections from html meta info.
  Non-standard names may introduce noise on encoding detection.

- [ ] `[_libs/encoding/util/encodings/encodings.cc:865]`
  Unify EncodingNameAliasToEncoding and EncodingFromName, or determine why such a
  unification is not possible.
  ----------------------------------------------------------------------

- [ ] `[_libs/encoding/util/encodings/encodings.h:48]`
  Include a SWIG workaround header file.

- [ ] `[_libs/encoding/util/encodings/encodings.h:55]`
  Make these static const Encoding values instead of macros.

- [ ] `[_libs/encoding/util/encodings/encodings.h:106]`
  the current implementation is likely incomplete.  It would be good to consider
  the full matrix of all pairs of encodings and to fish out all compatible pairs.

- [ ] `[_libs/encoding/util/encodings/encodings.h:151]`
  Get rid of this function. The only special-case we should need to worry about
  are visual encodings. Anything we need to do for all 'RTL' encodings we need to
  do for UTF-8 as well.

- [ ] `[_libs/encoding/util/encodings/encodings.h:165]`
  Get rid of this function. The only special-case we should need to worry about
  are visual encodings.



# _libs/encoding/util/languages

- [ ] `[_libs/encoding/util/languages/languages.cc:69]`
  Although Teragram has two output names "TG_UNKNOWN_LANGUAGE" and "Unknown",
  they are essentially the same. Need to unify them. "un" and "ut" are invented
  by us, not from ISO-639.

- [ ] `[_libs/encoding/util/languages/languages.h:33]`
  Include a header containing swig-compatible enum.

- [ ] `[_libs/encoding/util/languages/languages.h:137]`
  If we want to do anything special with multi-script languages we should create
  new 'languages' for each language+script, as we do for traditional vs.
  simplified Chinese. However most such languages are rare in use and even rarer
  on the web, so this is unlikely to be something we'll be concerned with for a
  while.



# _libs/marty_cpp

- [ ] `[_libs/marty_cpp/marty_cpp.h:685]`
  пока range_error не кидаем, но надо доделать

- [ ] `[_libs/marty_cpp/marty_cpp.h:2290]`
  Надо подумать, править баг и как его править

- [ ] `[_libs/marty_cpp/marty_cpp.h:3602]`
  Нужен каст к underlaying типу, если он задан. Сюда надо будет передавать
  шаблоны и строку underlaying типа

- [ ] `[_libs/marty_cpp/marty_cpp.h:4155]`
  Нужен каст к underlaying типу, если он задан. Сюда надо будет передавать
  шаблоны и строку underlaying типа



# _libs/marty_tr

- [ ] `[_libs/marty_tr/format_message.h:53]`
  Надо подумать на тему замены десятичного разделителя и разделителя разрядов

- [ ] `[_libs/marty_tr/format_message.h:264]`
  Не реализовано ! Десятичный разделитель - между целой и дробной частью

- [ ] `[_libs/marty_tr/format_message.h:268]`
  Не реализовано ! Разделитель груп разрядов и размер группы

- [ ] `[_libs/marty_tr/format_message.h:272]`
  Не реализовано ! Установка нац особенностей форматирования десятичных чисел,
  делает decSep и decGroup

- [ ] `[_libs/marty_tr/locales.h:1327]`
  Это не совсем безопасно, но если считать, что все настройки будут в однопотоке
  при запуске проги и потом не меняются, то норм Вообще подразумевается, что они
  никогда не будут меняться, что и так всё хорошо настроено



# _libs/marty_utf

- [ ] `[_libs/marty_utf/utf_impl.h:723]`
  Надо бы сделать: UTF-32 из string. UTF-32 из wstring. string  из UTF-32.
  wstring из UTF-32.



# _libs/umba

- [ ] `[_libs/umba/enum_helpers.h:475]`
  Сделать так же, как для QString

- [ ] `[_libs/umba/enum_helpers.h:483]`
  Сделать так же, как для QString

- [ ] `[_libs/umba/filesys_scanners.h:30]`
  Надо бы переименовать в umba::filesys::scanners

- [ ] `[_libs/umba/filesys_scanners.h:270]`
  Нужно что-то решать с отсутствующим расширением

- [ ] `[_libs/umba/filesys_scanners.h:487]`
  Нужно что-то решать с отсутствующим расширением

- [ ] `[_libs/umba/format_message.h:57]`
  Надо подумать на тему замены десятичного разделителя и разделителя разрядов

- [ ] `[_libs/umba/format_message.h:303]`
  Не реализовано ! Десятичный разделитель - между целой и дробной частью

- [ ] `[_libs/umba/format_message.h:307]`
  Не реализовано ! Разделитель груп разрядов и размер группы

- [ ] `[_libs/umba/format_message.h:311]`
  Не реализовано ! Установка нац особенностей форматирования десятичных чисел,
  делает decSep и decGroup

- [ ] `[_libs/umba/regex_helpers.h:197]`
  Если не обрезать, то регулярки в GCC 7.3 падают Чет не работает, а обрезать в
  прикладухе - работает

- [ ] `[_libs/umba/regex_helpers.h:232]`
  Если не обрезать, то регулярки в GCC 7.3 падают Чет не работает, а обрезать в
  прикладухе - работает

- [ ] `[_libs/umba/string_plus.h:2099]`
  Надо подумать, править баг и как его править

- [ ] `[_libs/umba/string_plus.h:2156]`
  Надо подумать, править баг и как его править

- [ ] `[_libs/umba/utf_impl.h:772]`
  Надо бы сделать: UTF-32 из string UTF-32 из wstring string  из UTF-32 wstring
  из UTF-32



# _libs/umba/internal

- [ ] `[_libs/umba/internal/filesys.h:587]`
  Посмотреть "Именование файлов, путей и пространств имен" -
  https://learn.microsoft.com/ru-ru/windows/win32/fileio/naming-a-file

- [ ] `[_libs/umba/internal/filesys.h:1487]`
  При возникновении исключения hFind утекает. Надо бы переделать, и такие моменты
  надо бы везде это проверить

- [ ] `[_libs/umba/internal/filesys.h:1546]`
  При возникновении исключения hFind утекает. Надо бы везде это проверить HANDLE
  hFind = ::FindFirstFileA( umba::filename::prepareForNativeUsage(path).c_str(),
  &fndData );

- [ ] `[_libs/umba/internal/filesys.h:1920]`
  Переделать !!!
  https://stackoverflow.com/questions/2910377/get-home-directory-in-linux

- [ ] `[_libs/umba/internal/winerror_org.h:34314]`
  Add DXG Win32 errors here
  
  Common errors {0x2000..0x20ff}
  
  MessageId: ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER
  
  MessageText:
  
  Exclusive mode ownership is needed to create unmanaged primary allocation.



# _libs/umba/warnings

- [ ] `[_libs/umba/warnings/disable_unsafe_conversion.h:9]`
  Проверить на 8/9/10/11/12 ой версии GCC - на 13ой точно есть

