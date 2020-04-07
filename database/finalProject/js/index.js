let Navbar = ReactBootstrap.Navbar
let Nav = ReactBootstrap.Nav
let CardGroup = ReactBootstrap.CardGroup
let Card = ReactBootstrap.Card
let Component = React.Component 

class AppNav extends Component{
	constructor(props){
		super(props);
	}
	render(){
		return(
		<Navbar className="mainNav" variant="dark">
		  <Navbar.Brand href="#home">Bracket Helper</Navbar.Brand>
		   <Nav className="mr-auto">
		      <Nav.Link href="Trivia/question.php">Trivia</Nav.Link>
		   </Nav>
		</Navbar>
		)
	}

}
class AppMain extends Component{
	render(){
		return(
		<div className="mainGrid">
		  <div className="mainText">
		    <h3>One Stop Shop March Madness Help</h3>
		    Whether you have been struggling in your family's NCAA tournament pool, trying to figure out what happened to your last bracket, or nerd out about previous tournaments, we have got you covered. Utilizing Kaggle's wonderful dataset of NCAA tournament information and history, we built this application to help YOU discover everything you want to know about the NCAA tournament history AND MORE!
		    <br />
		    Right now, test your knowledge of NCAA Tournament history by playing our extensive trivia that will push your knowledge of previous NCAA tournaments!
		  </div>
		  <div className="mainPics">
		    <img className="slidePic" src="img/trivia.jpg" />	
		    <button className="slideButton" onClick={() => {window.location.href="./Trivia/question.php"}}>Play Trivia</button>
		  </div>
		</div>
		)
	}
}
class AppDevelopers extends Component{
	render(){
		return(
		<div className="mainDevelopers">
		<h4>Meet the Developers</h4>
		<CardGroup className="developerCards">
		<Card className="text-center">
		  <Card.Body>
		    <Card.Img className="devImg" src="img/lo.jpg" />
		    <Card.Title>Liam Ormiston</Card.Title>
		  </Card.Body>
		</Card>
		<Card className="text-center">
		  <Card.Body>
		    <Card.Img className="devImg" src="img/am.jpg" />
		    <Card.Title>Andy Monroe</Card.Title>
		  </Card.Body>
		</Card>
		<Card className="text-center">
		  <Card.Body>
		    <Card.Img className="devImg" src="img/ag.jpg" />
		    <Card.Title>Andrew Growney</Card.Title>
		  </Card.Body>
		</Card>
		</CardGroup>
		</div>
		)
	}
}
class AppFooter extends Component{
	render(){
		return(
		<div className="mainFooter text-center">
		  <img onClick={() => {window.location.href="https://github.com/ajgrowney/647Final";}} src='img/github.svg' />
		</div>
		)
	}
}
class AppIndex extends Component{
	
	render(){
		return(
		<div>
		  <AppNav />
		  <AppMain />
		  <AppDevelopers />
		  <AppFooter />
		</div>
		);
	}

}


ReactDOM.render(<AppIndex />, document.getElementById('root'));

