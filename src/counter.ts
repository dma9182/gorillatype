export function setupCounter(element: HTMLButtonElement) {
  let counter = 0
  const setCounter = (count: number) => {
    counter = count
    element.innerHTML = `Click to add this : ${counter}`
  }
  element.addEventListener('click', () => {
    setCounter(counter + 1);
    console.log("count + 1");
  })

  setCounter(0)
}
