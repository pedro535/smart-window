import './app.css'

export function App() {

  const alertMessage = () => {
    alert("Hello World");
  }

  return (
    <>

    <div class="navbar bg-neutral text-neutral-content">
      <a class="btn btn-ghost normal-case text-2xl">SmartWindow</a>
    </div>

    <div class="container mx-auto">
      <button class="btn btn-primary w-64 rounded-full m-10" onClick={() => {alertMessage()}}>Button</button>
    </div>

    </>
  )
}