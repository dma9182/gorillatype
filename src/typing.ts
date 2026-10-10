// TODO:
// 1. read keyboard
// 2. change font opacity
// 3. click = change font opacity
// 4. misclick = change color

export function KeyListener() {
  document.addEventListener('keydown', (event) => {
    const output = document.querySelector('#typed')
    if (!output)
      return

    if (event) {
      console.log(event)
    }

    // yep a backspace function
    if (event.key === 'Backspace' || event.key === 'Delete') {
      output.textContent = output.textContent.slice(0,-1)
    }

    //instead of checking for every specific key why not just filter length == 1?
    else if (event.key.length === 1) {
      output.textContent += event.key
    }
  })
}
