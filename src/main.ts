import './style.css'
import './typing'
import { KeyListener } from './typing'

document.querySelector<HTMLDivElement>('#app')!.innerHTML =
`<section id="gorilla">
  <h1>Gorilla Type</h1>
  <p>Code typing speedtest</p>

<p id ="typed"></p>

</section>
`

KeyListener()
