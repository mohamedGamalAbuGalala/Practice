function reorderLines(
  logFileSize,
  logLines = [""]
) {
  // split the 2 logs number/character in 2 separated arrays
  const numberLines = [];
  let charLines = [];

  for (let i = 0; i < logFileSize; i++) {
    const line = logLines[i];
    const splitted = line.split(" ");

    // is this a number log, checking the last element of the log if its a number or not
    if (
      splitted[splitted.length - 1][0] >= "0" &&
      splitted[splitted.length - 1][0] <= "9"
    ) {
      numberLines.push(line);
    } else {
      // this is a character log, so I will make them in objects with identifier and value as keys
      const [identifier, ...value] = splitted;
      charLines.push({
        identifier,
        value: value.join(" "),
      });
    }
  }

  const reA = /[^a-zA-Z]/g;
  const reN = /[^0-9]/g;

  charLines.sort((a, b) => {
    if (a.value === b.value) {
      //   sort alphanumeric

      // get only char to sort on
      const aA = a.identifier.replace(reA, "");
      const bA = b.identifier.replace(reA, "");
      if (aA === bA) {
        // get numbers to sort on
        const aN = parseInt(
          a.identifier.replace(reN, ""),
          10
        );
        const bN = parseInt(
          b.identifier.replace(reN, ""),
          10
        );
        // sort on numbers
        return aN === bN ? 0 : aN > bN ? 1 : -1;
      } else {
        // sort on char
        return aA > bA ? 1 : -1;
      }
    }
    // sort by value
    return a.value > b.value ? 1 : -1;
  });

  // concatenating the char lines again into a line of log
  charLines = charLines.map(
    (cl) => `${cl.identifier} ${cl.value}`
  );

  // concatenating the charLines and numberLines
  let ret = [];
  if (charLines.length) ret = [...charLines];
  if (numberLines.length)
    ret = [...ret, ...numberLines];
  return ret;
}

console.log(
  reorderLines(5, [
    "a1 9 2 3 1",
    "a1 A ct car",
    "zo4 4 7",
    "ab1 o ff KEY dog",
    "a8 A ct car",
  ])
);
